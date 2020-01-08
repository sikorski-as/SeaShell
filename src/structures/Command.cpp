#include "Command.h"

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
void Command::setArguments(std::vector<Node*> args){
    this->arguments = args;
}
NodeType Command::getType() {
    return this->type;
}