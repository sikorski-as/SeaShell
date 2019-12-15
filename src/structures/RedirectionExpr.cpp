#include "RedirectionExpr.h"

RedirectionExpr::RedirectionExpr() {
    this->type = NodeType::REDIRECTION_EXPR;
}
RedirectionExpr::RedirectionExpr(Node* program, Node* input, Node* output) {
    this->program = program;
    this->type = NodeType::REDIRECTION_EXPR;
    this->input = input;
    this->output = output;
}
RedirectionExpr::~RedirectionExpr(){}
Node* RedirectionExpr::getProgram(){
    return this->program;
}
void RedirectionExpr::setProgram(Node* program){
    this->program = program;
}
Node* RedirectionExpr::getInput(){
    return this->input;
}
void RedirectionExpr::setInput(Node* input){
    this->input = input;
}
Node* RedirectionExpr::getOutput(){
    return this->output;
}
void RedirectionExpr::setOutput(Node* output){
    this->output = output;
}
NodeType RedirectionExpr::getType() {
    return this->type;
}