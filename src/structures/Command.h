#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include "Node.h"

class Command : public Node {
    public:
        Command();
        Command(Node* commandName, std::vector<Node*> arguments);
        ~Command();    
        Node* getCommandName();
        void setCommandName(Node* commandName);
        std::vector<Node*> getArguments();
        void setArguments(std::vector<Node*> arguments);
        NodeType getType() override;
        std::string toString() override;
    private:
        Node* commandName; //backTick expr / identifier
        std::vector<Node*> arguments;
};

#endif