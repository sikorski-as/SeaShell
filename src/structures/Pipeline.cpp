#include <sys/stat.h>
#include <sys/wait.h> // waitpid
#include <fcntl.h>
#include <unistd.h> // fork
#include <string>
#include <string.h>
#include <errno.h>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include "Pipeline.h"
#include <stdio.h>
#include <sstream>

extern std::vector<pid_t> childrenPids;

Pipeline::Pipeline(std::vector<Command> cmds)
: commands(cmds)
{}

std::string Pipeline::execute(Context* context, bool backtick) {
    char** argv = nullptr;
    std::string argString = "";
    int j = 0;
    char * tempAlloc = nullptr;

    int pipelineLength = this->commands.size();
    if(pipelineLength == 1){
        std::string commandName = this->commands[0].commandName.execute(context);
        if(commandName  == "cd"){
            if(this->commands[0].arguments.size() > 0){
                std::string dirName = this->commands[0].arguments[0].execute(context);
                context->setWorkingDirectory(dirName);
                return "";
            }
        }
        else if(commandName == "pwd"){
            return context->getWorkingDirectory();
        } else if (commandName == "exit") {
            exit(0);    
        }
    }
    
    
    pid_t pids[pipelineLength];
    std::time_t currentTimestamp = std::time(nullptr);
    std::string fifo_name_prefix = "/tmp/seashell_fifo."+std::to_string(currentTimestamp)+"."+std::to_string(getpid())+'.';
    for(int i = 0; i < pipelineLength; i++){
        std::string fifo_name = fifo_name_prefix + std::to_string(i);
        mkfifo(fifo_name.c_str(), 0666);
    }

    for (int i = 0; i < pipelineLength; i++){
        Command pipeCommand = commands[i];
        // std::cout<<"Forking "<<i<<std::endl;
        pid_t currPid = fork();
        if(currPid == 0) { // child process

            // stdin and stdout shenanigans with FIFO
            if(i == 0){
                int write_desc = open((fifo_name_prefix + std::to_string(i)).c_str(), O_WRONLY); // open first write FIFO
                dup2(write_desc,1);
                close(write_desc);
            } else {
                int read_desc = open((fifo_name_prefix + std::to_string(i-1)).c_str(), O_RDONLY); // open read FIFO
                int write_desc = open((fifo_name_prefix + std::to_string(i)).c_str(), O_WRONLY); // open write FIFO
                dup2(read_desc,0); // read FIFO descriptor to stdin
                close(read_desc);
                dup2(write_desc,1); // write FIFO descriptor to stdout
                close(write_desc);
            }

            //std::cerr<<"Input cnt: "<<pipeCommand.inputFile.size()<<std::endl;
            if(pipeCommand.inputFile.size() > 0){
                std::string stdinFilename = pipeCommand.inputFile.back().execute(context); // last input file becomes stdin
                std::string fullPath = context->getWorkingDirectory() + stdinFilename;
                //std::cerr<<"Input filename: "<<fullPath<<std::endl;
                int stdinFileDescriptor = open(fullPath.c_str(), O_RDONLY);
                // //std::cerr<<"File descriptor: "<<stdinFileDescriptor<<std::endl;
                //std::cerr<<"In file error: "<<strerror(errno)<<std::endl;
                dup2(stdinFileDescriptor, 0);
                close(stdinFileDescriptor);
            }

            //std::cerr<<"Output cnt: "<<pipeCommand.outputFile.size()<<std::endl;
            if(pipeCommand.outputFile.size() > 0){
                std::string stdoutFilename = pipeCommand.outputFile.back().execute(context); // last output file becomes stdout
                std::string fullPath = context->getWorkingDirectory() + stdoutFilename;
                //std::cerr<<"Output filename: "<<fullPath<<std::endl;
                int stdoutFileDescriptor = open(fullPath.c_str(), O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
                // //std::cerr<<"Out file descriptor: "<<stdoutFileDescriptor<<std::endl;
                //std::cerr<<"Out file error: "<<strerror(errno)<<std::endl;

                dup2(stdoutFileDescriptor, 1);
                close(stdoutFileDescriptor);
            }


            // actual command execution

            // BELOW FOR TESTING
            // std::cerr<<"CMD: "<<pipeCommand.commandName.execute(context)<<std::endl;
            // std::cerr<<"Arg array size: "<<pipeCommand.arguments.size()<<std::endl;

            argv = new char*[pipeCommand.arguments.size()+2];
            argv[0] = const_cast<char*>(pipeCommand.commandName.execute(context).c_str());
            for(j = 0; j < pipeCommand.arguments.size(); j++){
                argString = pipeCommand.arguments[j].execute(context);
                // std::cerr<<"ARG: "<<argString<<std::endl;
                tempAlloc = new char[pipeCommand.arguments[j].execute(context).length()];
                sprintf(tempAlloc, pipeCommand.arguments[j].execute(context).c_str());
                argv[j+1] = tempAlloc;
            }
            argv[pipeCommand.arguments.size()+1] = NULL;
            int result = execvp(argv[0], argv);
            if(result == -1){ 
                std::cerr<<strerror(errno)<<std::endl;
            }
            exit(0); // this gets executed when execvp yields error
        } else if(currPid < 0) {
            throw std::runtime_error("Unable to start subprocess for pipeline element: "+std::to_string(i));
        } else { // parent process
            pids[i] = currPid;
            childrenPids.push_back(currPid); // to handle signals
            // std::cout<<"Saving pid: "<<pids[i]<<std::endl;
        }
    }

    // Below fragment reachable only from parent
    std::stringstream output;
    std::ifstream last_read_desc{(fifo_name_prefix + std::to_string(pipelineLength-1)).c_str()};

    // if backtick then write to stringstream, else write to stdout
    std::copy(std::istreambuf_iterator<char>(last_read_desc),
         std::istreambuf_iterator<char>(),
         std::ostreambuf_iterator<char>(backtick ? output : std::cout));

    int status = 0;
    for(int i = 0; i < pipelineLength; i++){
        // std::cout<<"Waiting for: "<<pids[i]<<std::endl;
        waitpid(pids[i], &status, 0);
    }
    context->setLastReturnCode(status);

    for(int i = 0; i < pipelineLength; i++) // this works when all processes are finished
        unlink((fifo_name_prefix + std::to_string(i)).c_str());

    return output.str();
}


bool Pipeline::isEqual(VarPip* vp) {
    if(Pipeline* p = dynamic_cast<Pipeline*>(vp)) {
        if(this->commands.size() != p->commands.size())
            return false;
        int i = 0;
        for(auto c: this->commands) {
            if(!c.isEqual(p->commands[i]))
                return false;
            i++;
        }
        return true;
    }
    return false;
}
