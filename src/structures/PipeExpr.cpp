#include <sstream>
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

std::string PipeExpr::toString() {
    std::ostringstream imploded;
    for (auto pipe : this->pipes) {
        imploded << pipe->toString() << " ";
    }
    std::string ans = imploded.str();
    return ans.substr(0, ans.length() - 1);
}
