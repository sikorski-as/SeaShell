#include "VariableAssignmentTests.h"

// local = host
Program generateSimpleAssignment() {
    std::string variableName = "local";
    Identifier* assigned = new Identifier("host");
    VariableAssignment* varAssignment = new VariableAssignment(variableName, assigned);
    std::vector<Node*> commands;
    commands.push_back(varAssignment);
    return Program(commands);
}