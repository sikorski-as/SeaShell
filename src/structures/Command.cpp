#include "Command.h"

Command::Command() {
    this->type = NodeType::COMMAND;
}
Command::Command(std::string commandName, std::vector<Node> arguments) {
    this->commandName = commandName;
    this->arguments = arguments;
    this->type = NodeType::COMMAND;
}
Command::~Command(){}
std::string Command::getCommandName(){
    return this->commandName;
}
void Command::setCommandName(std::string commandName){
    this->commandName = commandName;
}
std::vector<Node> Command::getArguments(){
    return this->arguments;
}
void Command::setArguments(std::vector<Node> argumentse){
    this->arguments = arguments;
}
NodeType Command::getType() {
    return this->type;
}