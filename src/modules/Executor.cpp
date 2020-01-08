
#include <iostream>
#include <sys/stat.h>
#include <sys/wait.h> // waitpid
#include <fcntl.h>
#include <unistd.h> // fork
#include <string>
#include <string.h>
#include <errno.h>
#include <fstream>
#include "Executor.h"
#include "Context.h"
#include "../structures/VariableAssignment.h"
#include "../structures/Identifier.h"

bool Executor::isRunning() {
    return this->running;
}

void Executor::execute(Program &program) {
    std::cout << "Executing!\n";

    for (auto cmd: program.getCommands()) {
        try {
            // TODO wrap in try-catch
            // TODO exit
            auto type = cmd->getType();
            // TODO pobieraj stringi aby potem wyswietlac je na konsoli (aby dzialal backtick)
            switch (type) {
                case NodeType::VARIABLE_ASSIGNMENT:
                    std::cout << executeVariableAssignment(dynamic_cast<VariableAssignment*>(cmd)) << std::endl;
                    break;
                case NodeType::COMMAND:
                    std::cout << executeCommand(dynamic_cast<Command*>(cmd)) << std::endl;
                    break;
                case NodeType::REDIRECTION_EXPR:
                    std::cout << executeRedirectionExpression(dynamic_cast<RedirectionExpr*>(cmd))<< std::endl;
                    break;
                case NodeType::PIPE_EXPR:
                    std::cout << executePipeExpression(dynamic_cast<PipeExpr*>(cmd)) << std::endl;
                    break;
                case NodeType::BACKTICK_EXPR:
                    std::cout << executeBackTickExpression(dynamic_cast<BackTickExpr*>(cmd))<< std::endl;
                    break;
                default:
                    throw std::runtime_error("Unexpected input");
            }
        } catch (std::runtime_error error) {
            std::cout << error.what() << std::endl;
        }
    }

    this->running = false;
}

std::string Executor::executeProgram(Program &program) { // TODO test
    std::string output = "";
    for (auto cmd: program.getCommands()) {
        try {
            auto type = cmd->getType();
            switch (type) {
                case NodeType::VARIABLE_ASSIGNMENT:
                    output += executeVariableAssignment(dynamic_cast<VariableAssignment*>(cmd));
                    break;
                case NodeType::COMMAND:
                    output += executeCommand(dynamic_cast<Command*>(cmd));
                    break;
                case NodeType::REDIRECTION_EXPR:
                    output += executeRedirectionExpression(dynamic_cast<RedirectionExpr*>(cmd));
                    break;
                case NodeType::PIPE_EXPR:
                    output += executePipeExpression(dynamic_cast<PipeExpr*>(cmd));
                    break;
                case NodeType::BACKTICK_EXPR: {
                    std::string command = executeBackTickExpression(dynamic_cast<BackTickExpr*>(cmd));
                    // TODO sprobuj wykonac to jako komendę - wbudowaną lub nie?
                    break;
                }
                default:
                    throw std::runtime_error("Unexpected input");
        }
        } catch (std::runtime_error error) {
            output += error.what();
        }
    }

    return output;
}


std::string Executor::executeVariableAssignment(VariableAssignment *varAssignment) {
    auto assignable = varAssignment->getValue();
    auto type = assignable->getType();
    if(type == NodeType::BACKTICK_EXPR){
        throw std::runtime_error("TODO");
        std::string value = executeBackTickExpression(dynamic_cast<BackTickExpr*>(assignable));
        this->context.setVariable(varAssignment->getName(), value);
        // std::cout << "[executeVariableAssignment] BACKTICK : " << this->context.getVariable(varAssignment->getName()) << std::endl;
    }
    else if(type == NodeType::IDENTIFIER){
        auto value = dynamic_cast<Identifier*>(assignable);
        // TODO value powinno być sprawdzane pod kątem replacowania zmiennych
        this->context.setVariable(varAssignment->getName(), value->getIdentifier());
        // std::cout << "[executeVariableAssignment] IDENT : " << this->context.getVariable(varAssignment->getName()) << std::endl;
    } else if(type == NodeType::VARIABLE_CALL) {
        auto variableCall = dynamic_cast<VariableCall*>(assignable);
        std::string variableContent = this->context.getVariable(variableCall->getName());
        this->context.setVariable(varAssignment->getName(), variableContent);
        // std::cout << "[executeVariableAssignment] VAR_CALL : " << this->context.getVariable(varAssignment->getName()) << std::endl;
    } else 
        throw std::runtime_error("Unexpected type in the variable assignment");
    
    return EMPTY_STRING;
}

std::string Executor::executeCommand(Command *command) {
    Node* commandName = command->getCommandName(); //backTick expr / identifier
    std::vector<Node*> arguments = command->getArguments(); // TODO przekazujac argumenty jesli IDENTIFIER powinno być sprawdzane pod kątem replacowania zmiennych
    NodeType commandNameType = commandName->getType();
    if(commandNameType == NodeType::IDENTIFIER) {
        // TODO sprawdz czy wbudowane czy niewbudowane
        throw std::runtime_error("TODO");
    } else if(commandNameType == NodeType::BACKTICK_EXPR) {
        throw std::runtime_error("TODO");
    } else {
        throw std::runtime_error("Unexpected type in the command");
    }

    return ""; // TODO
}

std::string Executor::executeRedirectionExpression(RedirectionExpr* redirectionExpr) {
    Node* command = redirectionExpr->getCommand(); // identifier / backtickexpr / command? TODO
    Node* input = redirectionExpr->getInput();
    Node* output = redirectionExpr->getOutput();

    NodeType type = command->getType();
    if(type == NodeType::BACKTICK_EXPR){
        throw std::runtime_error("TODO");
    } else if(type == NodeType::IDENTIFIER) {
        throw std::runtime_error("TODO");
    } else if(type == NodeType::COMMAND) {
        throw std::runtime_error("TODO");
    } else {
         throw std::runtime_error("Unexpected type in the redirection expression");
    }

    return ""; // TODO
}

std::string Executor::executePipeExpression(PipeExpr* pipeExpr) {
    std::vector<Node*> pipes = pipeExpr->getPipes();
    int pipelineLength = pipes.size();
    pid_t pids[pipelineLength];
    std::string fifo_name_prefix = "/tmp/seashell_fifo.";
    for(int i = 0; i < pipelineLength; i++){
        std::string fifo_name = fifo_name_prefix + std::to_string(i);
        mkfifo(fifo_name.c_str(), 0666);
    }

    for (int i = 0; i < pipelineLength; i++){
        Node* pipeNode = pipes[i];
        NodeType nodeType = pipeNode->getType();
        // std::cout<<"Forking "<<i<<std::endl;
        pid_t currPid = fork();
        if(currPid == 0) { // child process
            
            // stdin and stdout with FIFO shenanigans
            if(i == 0){
                int write_desc = open((fifo_name_prefix + std::to_string(i)).c_str(), O_WRONLY); // open first write FIFO
                dup2(write_desc,1);
                close(write_desc);
                close(0);
            } else {
                int read_desc = open((fifo_name_prefix + std::to_string(i-1)).c_str(), O_RDONLY); // open read FIFO
                int write_desc = open((fifo_name_prefix + std::to_string(i)).c_str(), O_WRONLY); // open write FIFO
                dup2(read_desc,0); // read FIFO descriptor to stdin
                close(read_desc);
                dup2(write_desc,1); // write FIFO descriptor to stdout
                close(write_desc);
            }

            // actual command execution
            switch(nodeType){
                case NodeType::COMMAND:
                    auto cmdNode = dynamic_cast<Command*>(pipeNode);
                    // executeCommand(cmdNode);

                    // BELOW FOR TESTING
                    Identifier* cmdName = dynamic_cast<Identifier*>(cmdNode->getCommandName());
                    std::string cmdNameString = cmdName->getIdentifier();
                    // std::cout<<"CMD: "<<cmdNameString<<std::endl;
                    
                    std::vector<Node*> cmdArgs = cmdNode->getArguments();
                    // std::cout<<"Size: "<<cmdArgs.size()<<std::endl;
                    char* argv[cmdArgs.size()+2];
                    argv[0] = const_cast<char*>(cmdNameString.c_str());
                    for(int j = 1; j <= cmdArgs.size(); j++){
                        auto arg = cmdArgs[j-1];
                        Identifier* identifierArg = dynamic_cast<Identifier*>(arg);
                        std::string argString = identifierArg->getIdentifier();
                        // std::cout<<argString<<std::endl;
                        argv[j] = const_cast<char*>(argString.c_str());
                    }
                    argv[cmdArgs.size()+1] = NULL;
                    int outCode = execvp(argv[0], argv);
                    // std::cout<<"OUTCODE: "<<outCode<<" for: "<<i<<std::endl;
                    if(outCode < 0) exit(0);
                    // std::cout<<strerror(errno)<<std::endl;
                break;
            }
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

std::string Executor::executeBackTickExpression(BackTickExpr* backTickExpr) {
    Program* p = backTickExpr->getProgram();
    Context old = this->context; // TODO copy old context

    throw std::runtime_error("TODO TEST");
    std::string backTickString =  this->executeProgram(*p); // TODO w takim razie wywolanie execute powinno byc rozbite na execute i executeProgram i context powinien byc nowy tworzony

    this->context = old; // TODO restore context

    return backTickString;

    // lolek = 1234; echo `lolek=5678; echo $lolek` $lolek
    // wypisuje: 5678 1234
}



