#ifndef UXP_VALUE_H
#define UXP_VALUE_H

#include <string>
#include "Program.h"
#include "../modules/Context.h"

class Value {
protected:
    std::string value;
    Program *program;

public:
    explicit Value(std::string);
    explicit Value(Program*);
    Value() = default;
    Value(Value const &) = default;

    std::string execute(Context *context = nullptr);
};


#endif //UXP_VALUE_H
