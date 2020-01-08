#include <sstream>
#include "Program.h"

Program::Program() {
    this->type = NodeType::PROGRAM;
}
Program::Program(std::vector<Node*> commands) {
    this->commands = commands;
    this->type = NodeType::PROGRAM;
}
Program::~Program(){}
std::vector<Node*> Program::getCommands(){
    return this->commands;
}
void Program::setCommands(std::vector<Node*> commands){
    this->commands = commands;
}
NodeType Program::getType() {
    return this->type;
}

std::string Program::toString() {
    std::ostringstream imploded;
    for (auto command : this->commands) {
        imploded << command->toString() << " ";
    }
    std::string ans = imploded.str();
    return ans.substr(0, ans.length() - 1);
}
