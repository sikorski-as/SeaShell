
#include <iostream>
#include "Executor.h"
#include "Context.h"
#include "../structures/VariableAssignment.h"
#include "../structures/Identifier.h"

bool Executor::isRunning() {
    return this->running;
}

void Executor::execute(Program &program) {
    std::cout << "Executing!\n";

    for (auto cmd: program.getCommands()) {
        auto type = cmd->getType();
        switch (type) {
            case NodeType::VARIABLE_ASSIGNMENT:
                executeVariableAssignment(dynamic_cast<VariableAssignment*>(cmd));
                break;
            default:
                break;
        }
    }

    this->running = false;
}

void Executor::executeVariableAssignment(VariableAssignment *varAssignment) {
    auto assignable = varAssignment->getValue();
    auto type = assignable->getType();
    if(type == NodeType::BACKTICK_EXPR){
        throw std::runtime_error("TODO");
    }
    else if(type == NodeType::IDENTIFIER){
        auto value = dynamic_cast<Identifier*>(assignable);
        // stripowanie cudzysłowów powinno być w interpreterze
        this->context.setVariable(varAssignment->getName(), value->getIdentifier());
    }
}

