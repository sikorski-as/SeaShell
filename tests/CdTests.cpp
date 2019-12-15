#include "CdTests.h"

// cd test_folder
Program generateSimpleCd() {
    Identifier commandName = Identifier("cd");
    std::vector<Node*> arguments;
    Identifier folderName = Identifier("test_folder");
    arguments.push_back(&folderName);
    Command c = Command(&commandName, arguments);
    std::vector<Node*> commands;
    commands.push_back(&c);
    return Program(commands);
}

