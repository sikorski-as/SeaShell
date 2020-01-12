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