#include "PipeExpr.h"

PipeExpr::PipeExpr() {
    this->type = NodeType::PIPE_EXPR;
}
PipeExpr::PipeExpr(std::vector<Node*> pipes) {
    this->pipes = pipes;
    this->type = NodeType::PIPE_EXPR;
}
PipeExpr::~PipeExpr(){}
std::vector<Node*> PipeExpr::getPipes(){
    return this->pipes;
}
void PipeExpr::setPipes(std::vector<Node*> pipese){
    this->pipes = pipes;
}
NodeType PipeExpr::getType() {
    return this->type;
}