#include "ExportTests.h"
#include "../src/structures/Program.h"

// export a = "aaaa"
Program generateSimpleExport() {
    Identifier commandName = Identifier("export");
    std::vector<Node*> arguments;
    Identifier assigned = Identifier("\"aaaa\"");
    VariableAssignment varAssignment = VariableAssignment("a", &assigned);
    arguments.push_back(&varAssignment);
    Command c = Command(&commandName, arguments);
    std::vector<Node*> commands;
    commands.push_back(&c);
    return Program(commands);
}