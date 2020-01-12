
#include "Command.h"

 bool Command::isEqual(Command c) {
    if(!(this->commandName.isEqual(c.commandName)))
        return false;
    if(this->arguments.size() != c.arguments.size())
        return false;
    if(this->inputFile.size() != c.inputFile.size())
        return false;
    if(this->outputFile.size() != c.outputFile.size())
        return false;    
    int i = 0;
    for(auto el : this->arguments) {
        if(!el.isEqual(c.arguments[i]))
            return false;
        i++;
    }
    i = 0;
    for(auto el : this->inputFile) {
        if(!el.isEqual(c.inputFile[i]))
            return false;
        i++;
    }
    i = 0;
    for(auto el : this->outputFile) {
        if(!el.isEqual(c.outputFile[i]))
            return false;
        i++;
    }
    return true;
 }