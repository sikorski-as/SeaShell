#ifndef UXP_VARIABLE_H
#define UXP_VARIABLE_H


#include "VarPip.h"
#include "Value.h"

class Variable : public VarPip {
public:
    bool shouldExport;
    Value name;
    Value newValue;

    Variable(Variable const &) = default;

    Variable(Value const&, Value const&, bool = false);

    std::string execute(Context *) override ;
};


#endif //UXP_VARIABLE_H
