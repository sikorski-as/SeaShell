#include "VariableCall.h"

VariableCall::VariableCall() {
    this->type = NodeType::VARIABLE_CALL;
}
VariableCall::VariableCall(std::string name) {
    this->name = name;
    this->type = NodeType::VARIABLE_CALL;
}
VariableCall::~VariableCall(){}   
std::string VariableCall::getName(){
    return this->name;
}
void VariableCall::setName(std::string name){
    this->name = name;
}
NodeType VariableCall::getType() {
    return this->type;
}
