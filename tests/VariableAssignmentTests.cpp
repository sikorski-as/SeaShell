#include "VariableAssignmentTests.h"

// local = host
Program generateSimpleAssignment() {
    Value* name = new Value("local");
    Value* newValue = new Value("host");

    Variable* v = new Variable(*name, *newValue);

    std::vector<VarPip *> varpips = {v};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}