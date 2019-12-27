#include "RedirectionExpr.h"

RedirectionExpr::RedirectionExpr() {
    this->type = NodeType::REDIRECTION_EXPR;
}
RedirectionExpr::RedirectionExpr(Node* command, Node* input, Node* output) {
    this->command = command;
    this->type = NodeType::REDIRECTION_EXPR;
    this->input = input;
    this->output = output;
}
RedirectionExpr::~RedirectionExpr(){}
Node* RedirectionExpr::getCommand(){
    return this->command;
}
void RedirectionExpr::setCommand(Node* command){
    this->command = command;
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