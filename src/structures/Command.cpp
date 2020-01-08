#include "Command.h"
#include <sstream>

Command::Command() {
    this->type = NodeType::COMMAND;
}
Command::Command(Node* commandName, std::vector<Node*> arguments) {
    this->commandName = commandName;
    this->arguments = arguments;
    this->type = NodeType::COMMAND;
}
Command::~Command(){}
Node* Command::getCommandName(){
    return this->commandName;
}
void Command::setCommandName(Node* commandName){
    this->commandName = commandName;
}
std::vector<Node*> Command::getArguments(){
    return this->arguments;
}
void Command::setArguments(std::vector<Node*> arguments){
    this->arguments = arguments;
}
NodeType Command::getType() {
    return this->type;
}

std::string Command::toString() {
    std::ostringstream imploded;
    imploded << this->commandName->toString();
    for (auto arg : this->arguments) {
        imploded << " " << arg->toString();
    }
    return imploded.str();
}
