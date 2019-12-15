#ifndef BACK_TICK_EXPR_H
#define BACK_TICK_EXPR_H

#include <string>
#include "Assignable.h"
#include "Program.h"

class BackTickExpr : public Assignable {
    public:
        BackTickExpr(Program program);
        BackTickExpr();
        ~BackTickExpr();    
        Program getProgram();
        void setProgram(Program program);
        NodeType getType();
    private:
        Program program;
};

#endif