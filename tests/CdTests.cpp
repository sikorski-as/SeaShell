#include "CdTests.h"

// cd test_folder
Program generateSimpleCd() {
    Value* commandName = new Value("cd");
    Value *arg = new Value("test_folder");
    std::vector<Value> arguments = {*arg};

    Command* c = new Command();
    c->arguments = arguments;
    c->commandName = *commandName;
    std::vector<Command> commands = {*c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}


void testParserGenerateSimpleCd() {
    Program *p = parse("cd test_folder");
    Program t = generateSimpleCd();
    assert(p->isEqual(&t));
}