
#include "Value.h"


std::string Value::execute(Context *context) {
    if (program == nullptr) {
        return context->resolveVariables(value);
    } else {
        value = program->execute(context, true); // backtick = true
        delete program;
        program = nullptr;
        return context->resolveVariables(value);
    }
}

Value::Value(std::string value) {
    this->value = value;
    this->program = nullptr;
}

Value::Value(Program *program) {
    this->program = program;
}

bool Value::isEqual(Value v) {
    if(this->program == nullptr) {
        if(v.program != nullptr)
            return false;
        if(v.value != this->value)
            return false;
    } else {
        if(v.program == nullptr)
            return false;
        if(!v.program->isEqual(this->program))
            return false;
    }
    return true;
}
