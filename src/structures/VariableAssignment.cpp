#include "VariableAssignment.h"

VariableAssignment::VariableAssignment() {
    this->type = NodeType::VARIABLE_ASSIGNMENT;
}
VariableAssignment::VariableAssignment(std::string name, Assignable* assigned) {
    this->name = name;
    this->assigned = assigned;
    this->type = NodeType::VARIABLE_ASSIGNMENT;
}
VariableAssignment::~VariableAssignment(){}
std::string VariableAssignment::getName(){
    return this->name;
}
void VariableAssignment::setName(std::string name){
    this->name = name;
}
Assignable* VariableAssignment::getValue(){
    return this->assigned;
}
void VariableAssignment::setValue(Assignable* assigned){
    this->assigned = assigned;
}
NodeType VariableAssignment::getType() {
    return this->type;
}

std::string VariableAssignment::toString() {
    return this->name + " = " + this->assigned->toString();
}
