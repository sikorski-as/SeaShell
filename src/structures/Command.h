#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include "Node.h"

class Command : public Node {
    public:
        Command();
        Command(std::string commandName, std::vector<Node> arguments);
        ~Command();    
        std::string getCommandName();
        void setCommandName(std::string commandName);
        std::vector<Node> getArguments();
        void setArguments(std::vector<Node> arguments);
        NodeType getType();
    private:
        std::string commandName;
        std::vector<Node> arguments;
};

#endif