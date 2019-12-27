#include "ExportTests.h"
#include "../src/structures/Program.h"

// export a = "aaaa"
Program generateSimpleExport() {
    Identifier* commandName = new Identifier("export");
    std::vector<Node*> arguments;
    Identifier* assigned = new Identifier("aaaa");
    VariableAssignment* varAssignment = new VariableAssignment("a", assigned);
    arguments.push_back(varAssignment);
    Command* c = new Command(commandName, arguments);
    std::vector<Node*> commands;
    commands.push_back(c);
    return Program(commands);
}