#include "PwdTests.h"

// "pwd"
Program generateSimplePwd(){
    Identifier commandName = Identifier("pwd");
    std::vector<Node*> arguments;
    Command c = Command(&commandName, arguments);
    std::vector<Node*> commands;
    commands.push_back(&c);
    return Program(commands);
}
