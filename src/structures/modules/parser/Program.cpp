#include "Program.h"

Program::Program() {
    this->type = NodeType::PROGRAM;
}
Program::Program(std::vector<Node> commands) {
    this->commands = commands;
    this->type = NodeType::PROGRAM;
}
Program::~Program(){}
std::vector<Node> Program::getCommands(){
    return this->commands;
}
void Program::setCommands(std::vector<Node> commandse){
    this->commands = commands;
}
NodeType Program::getType() {
    return this->type;
}