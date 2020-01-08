
#include <stdexcept>
#include "Variable.h"

std::string Variable::execute(Context *) {
    throw std::runtime_error("TODO: Variable::execute");
}

Variable::Variable(Value const &name, Value const &newValue, bool shouldExport)
        : name(name), newValue(newValue), shouldExport(shouldExport) {}
