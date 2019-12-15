#include "VariableAssignmentTests.h"

// local = host
Program generateSimpleAssignment() {
    std::string variableName = "local";
    Identifier assigned = Identifier("host");
    VariableAssignment varAssignment = VariableAssignment(variableName, &assigned);
    std::vector<Node*> commands;
    commands.push_back(&varAssignment);
    return Program(commands);
}