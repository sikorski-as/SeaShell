#include "PwdTests.h"

// "pwd"
Program generateSimplePwd(){
    Value* commandName = new Value("pwd");

    Command* c = new Command();
    c->commandName = *commandName;
    std::vector<Command> commands = {*c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}

void testParserGenerateSimplePwd() {
    Program *p = parse("pwd");
    Program t = generateSimplePwd();
    assert(p->isEqual(&t));
}