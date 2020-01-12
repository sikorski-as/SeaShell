
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
#include "Pipeline.h"

Pipeline::Pipeline(std::vector<Command> cmds)
: commands(cmds)
{}

std::string Pipeline::execute(Context* context) {
    // std::vector<Node*> pipes = pipeExpr->getPipes();
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
        }
    }
    
    
    pid_t pids[pipelineLength];
    std::string fifo_name_prefix = "/tmp/seashell_fifo.";
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

            if(pipeCommand.inputFile.size() > 0){
                std::string stdinFilename = pipeCommand.inputFile.back().execute(); // last input file becomes stdin
                std::string fullPath = context->getWorkingDirectory() + stdinFilename;
                // std::cerr<<"Input filename: "<<fullPath<<std::endl;
                int stdinFileDescriptor = open(fullPath.c_str(), O_RDONLY);
                // std::cerr<<"File descriptor: "<<stdinFileDescriptor<<std::endl;
                // std::cerr<<"In file error: "<<strerror(errno)<<std::endl;
                dup2(stdinFileDescriptor, 0);
                close(stdinFileDescriptor);
            }

            if(pipeCommand.outputFile.size() > 0){
                std::string stdoutFilename = pipeCommand.outputFile.back().execute(); // last output file becomes stdout
                std::string fullPath = context->getWorkingDirectory() + stdoutFilename;
                // std::cerr<<"Output filename: "<<fullPath<<std::endl;
                int stdoutFileDescriptor = open(fullPath.c_str(), O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
                // std::cerr<<"Out file descriptor: "<<stdoutFileDescriptor<<std::endl;
                // std::cerr<<"Out file error: "<<strerror(errno)<<std::endl;

                dup2(stdoutFileDescriptor, 1);
                close(stdoutFileDescriptor);
            }


            // actual command execution

            // BELOW FOR TESTING
            std::string cmdNameString = pipeCommand.commandName.execute(context);
            // std::cerr<<"CMD: "<<cmdNameString<<std::endl;
            
            std::vector<Value> cmdArgs = pipeCommand.arguments;
            // std::cerr<<"Arg array size: "<<cmdArgs.size()<<std::endl;

            char* argv[cmdArgs.size()+2];
            argv[0] = const_cast<char*>(cmdNameString.c_str());
            for(int j = 1; j <= cmdArgs.size(); j++){
                auto arg = cmdArgs[j-1];
                std::string argString = arg.execute();
                // std::cerr<<"ARG: "<<argString<<std::endl;
                argv[j] = const_cast<char*>(argString.c_str());
            }
            argv[cmdArgs.size()+1] = NULL;
            execvp(argv[0], argv);
            exit(0); // this gets executed when execvp yields error
            // std::cout<<strerror(errno)<<std::endl;
        } else if(currPid < 0) {
            throw std::runtime_error("Unable to start subprocess for pipeline element: "+std::to_string(i));
        } else { // parent process
            pids[i] = currPid;
            // std::cout<<"Saving pid: "<<pids[i]<<std::endl;
        }
    }

    // Below fragment reachable only from parent
    std::string output = "";
    std::ifstream last_read_desc{(fifo_name_prefix + std::to_string(pipelineLength-1)).c_str()};
    for (std::string line; std::getline(last_read_desc, line);) {
        output += line;
    }
    last_read_desc.close();

    for(int i = 0; i < pipelineLength; i++){
        int status = 0;
        // std::cout<<"Waiting for: "<<pids[i]<<std::endl;
        waitpid(pids[i], &status, 0);
    }

    for(int i = 0; i < pipelineLength; i++) // this works when all processes are finished
        unlink((fifo_name_prefix + std::to_string(i)).c_str());

    return output;
}
