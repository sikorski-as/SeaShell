#include "BackTickExpr.h"

BackTickExpr::BackTickExpr() {
    this->type = NodeType::BACKTICK_EXPR;
}
BackTickExpr::BackTickExpr(Program program) {
    this->type = NodeType::BACKTICK_EXPR;
    this->program = program;
}
BackTickExpr::~BackTickExpr(){}   
Program BackTickExpr::getProgram(){
    return this->program;
}
void BackTickExpr::setProgram(Program program){
    this->program = program;
}
NodeType BackTickExpr::getType() {
    return this->type;
}
