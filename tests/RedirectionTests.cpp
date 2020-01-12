#include "RedirectionTests.h"

// ls > out.txt
Program generateOutputRedirection() {
    // grep aaa > filtered.txt
    Value* commandName2 = new Value("ls");
    Value *out2 = new Value("out.txt");
    std::vector<Value> outs2 = {*out2};

    Command* c2 = new Command();
    c2->commandName = *commandName2;
    c2->outputFile = outs2;

    std::vector<Command> commands = {*c2};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}

// wc < in.txt
Program generateInputRedirection() {
    Value* commandName = new Value("cat");
    Value *in = new Value("in.txt");
    std::vector<Value> ins = {*in};

    Command* c = new Command();
    c->inputFile = ins;
    c->commandName = *commandName;

    std::vector<Command> commands = {*c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}

// grep < in.txt >out.txt aaa
Program generateBothWayRedirection() {
    Value* commandName = new Value("grep");
    Value *in = new Value("in2.txt");
    std::vector<Value> ins = {*in};
    Value *out = new Value("out2.txt");
    std::vector<Value> outs = {*out};
    Value *arg = new Value("aaa");
    std::vector<Value> arguments = {*arg};
    
    Command* c = new Command();
    c->inputFile = ins;
    c->outputFile = outs;
    c->arguments = arguments;
    c->commandName = *commandName;

    std::vector<Command> commands = {*c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}