#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>
#include "Builtins.h"
#include "Context.h"

std::string builtin(Command & cmd, Context * context, bool backtick) {
    std::stringstream output;
    std::string commandName = cmd.commandName.execute(context);

    if(commandName  == "cd"){
        if(cmd.arguments.size() > 0){
            std::string dirName = cmd.arguments[0].execute(context);
            context->setWorkingDirectory(dirName);
        }
    }
    else if(commandName == "pwd"){
        output << context->getWorkingDirectory();
    } else if (commandName == "exit") {
        exit(0);
    }

    if(backtick){
        return output.str();
    }
    else{
        // if backtick then write to stringstream, else write to stdout
        std::copy(std::istreambuf_iterator<char>(output),
                  std::istreambuf_iterator<char>(),
                  std::ostreambuf_iterator<char>(std::cout));
        return "";
    }

}

bool isBuiltin(std::string commandName){
    return commandName == "pwd" || commandName == "cd" || commandName == "exit";
}