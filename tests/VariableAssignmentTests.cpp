#include "VariableAssignmentTests.h"

// local = host
Program generateSimpleAssignment() {
    std::string variableName = "local";
    auto assigned = new Identifier("host");
    auto varAssignment = new VariableAssignment(variableName, assigned);
    std::vector<Node*> commands;
    commands.push_back(varAssignment);
    return Program(commands);
}