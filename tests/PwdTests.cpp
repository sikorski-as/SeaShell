#include "TestInclude.h"

// "pwd"
Program generateSimplePwd(){
    std::string commandName = "pwd";
    std::vector<Node> arguments;
    Command c = Command(commandName, arguments);
    std::vector<Node> commands;
    commands.push_back((Node) c);
    return Program(commands);
}
