#include "EchoTests.h"

// echo "msg"
Program generateSimpleEcho(std::string echoArg) {
    Value* commandName = new Value("echo");
    Value* name = new Value(echoArg);
    std::vector<Value> arguments = {*name};

    Command* c = new Command();
    c->commandName = *commandName;
    c->arguments = arguments;

    std::vector<Command> commands = {*c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}

// echo "$PATH"
Program generateEchoSystemVariable() {
    Value* commandName = new Value("echo");
    Value* name = new Value("$PATH");
    std::vector<Value> arguments = {*name};

    Command* c = new Command();
    c->commandName = *commandName;
    c->arguments = arguments;

    std::vector<Command> commands = {*c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}

// echo "$PATH $PATH"
Program generateEchoSystemManyVariable() {
    Value* commandName = new Value("echo");
    Value* name = new Value("$PATH $PATH");
    std::vector<Value> arguments = {*name};

    Command* c = new Command();
    c->commandName = *commandName;
    c->arguments = arguments;

    std::vector<Command> commands = {*c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}



void testParserGenerateSimpleEcho(std::string echoArg) {
    Program *p = parse("echo " +  echoArg);
    Program t = generateSimpleEcho(echoArg);
    assert(p->isEqual(&t));
}

void testParserGenerateEchoSystemVariable() {
    Program *p = parse("echo \"$PATH\"");
    Program t = generateEchoSystemVariable();
    assert(p->isEqual(&t));
}

void testParserGenerateEchoSystemManyVariable() {
    Program *p = parse("echo \"$PATH $PATH\"");
    Program t = generateEchoSystemManyVariable();
    assert(p->isEqual(&t));
}