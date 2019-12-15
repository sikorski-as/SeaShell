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