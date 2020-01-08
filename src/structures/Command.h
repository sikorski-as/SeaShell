#ifndef UXP_COMMAND_H
#define UXP_COMMAND_H

#include <vector>
#include <string>
#include "Value.h"

class Command {
public:
    std::string commandName;
    std::vector<Value> arguments;
    Value inputFile;
    Value outputFile;
};


#endif //UXP_COMMAND_H
