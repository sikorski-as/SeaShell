#include "CdTests.h"

// cd test_folder
Program generateSimpleCd() {
    Identifier* commandName = new Identifier("cd");
    std::vector<Node*> arguments;
    Identifier* folderName = new Identifier("test_folder");
    arguments.push_back(folderName);
    Command* c = new Command(commandName, arguments);
    std::vector<Node*> commands;
    commands.push_back(c);
    return Program(commands);
}

