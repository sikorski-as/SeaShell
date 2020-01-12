
#include "Value.h"


std::string Value::execute(Context *context) {
    if (program == nullptr) {
        return context->resolveVariables(value);
    } else {
        return context->resolveVariables(program->execute(context));
    }
}

Value::Value(std::string value) {
    this->value = value;
}

Value::Value(Program *program) {
    this->program = program;
}
