#ifndef UXP_COMMAND_H
#define UXP_COMMAND_H

#include <vector>
#include <string>
#include "Value.h"

class Command {
public:
    std::string commandName;
    std::vector<Value> arguments;
    std::vector<Value> inputFile; // wc < a.txt < b.txt przyjmuje tylko argument b i wykonuje wc
    std::vector<Value> outputFile; // echo "dupa" >"a.txt" >"b.txt" spowoduje ze tylko w b bedzie dupa, a a sie utworzy i nic w nim nie bedzie
};


#endif //UXP_COMMAND_H
