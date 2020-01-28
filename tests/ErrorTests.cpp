#include "ErrorTests.h"

//cd nonExistingFolder
Program cdToNonExistingFolder() {
    Value commandName = Value("cd");
    Value name = Value("nonExistingFolder");
    std::vector<Value> arguments = {name};
    Command c = Command();
    c.commandName = commandName;
    c.arguments = arguments;
    std::vector<Command> commands = {c};
    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}