
#include <stdexcept>
#include "Variable.h"

std::string Variable::execute(Context *c, bool) { // ignore bool backtick
    std::string name = this->name.execute(c);
    std::string newValue = c->resolveVariables(this->newValue.execute(c));

    if(this->shouldExport)
        c->exportVariable(name, newValue);
    else
        c->setVariable(name, newValue);

    return "";
}

Variable::Variable(Value const &name, Value const &newValue, bool shouldExport)
        : name(name), newValue(newValue), shouldExport(shouldExport) {}


bool Variable::isEqual(VarPip * vp) {
    if(Variable* v = dynamic_cast<Variable*>(vp)) {
       if(v->shouldExport != this->shouldExport)
        return false;
       if(!(v->newValue).isEqual(this->newValue))
        return false;
       if(!(v->newValue).isEqual(this->newValue))
        return false;
       return true; 
    }
    return false;
}