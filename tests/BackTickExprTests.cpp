#include "BackTickExprTests.h"

Program generateSimpleBackTick() {

    Program echoPwdProgram = generateSimpleEcho("pwd");

    Value commandName = Value(&echoPwdProgram);
   
    Command c = Command();
    c.commandName = commandName;
    std::vector<Command> commands = {c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}