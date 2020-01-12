#include "PipeTests.h"

// echo "a bb" | wc
Program generateSimplePipe() {
    // echo "a bb"
    Value* commandName = new Value("echo");
    Value *arg = new Value("a bb");
    std::vector<Value> arguments = {*arg};

    Command* c = new Command();
    c->arguments = arguments;
    c->commandName = *commandName;

    //wc
    Value* commandName2 = new Value("wc");
    Command* c2 = new Command();
    c2->commandName = *commandName2;

    std::vector<Command> commands = {*c, *c2};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}

// cat in.txt | grep aaa | wc
Program generateManyPipes() {
    // cat in.txt
    Value* commandName = new Value("cat");
    Value *arg = new Value("in.txt");
    std::vector<Value> arguments = {*arg};

    Command* c = new Command();
    c->arguments = arguments;
    c->commandName = *commandName;

    // grep aaa
    Value* commandName2 = new Value("grep");
    Value *arg2 = new Value("aaa");
    std::vector<Value> arguments2 = {*arg2};

    Command* c2 = new Command();
    c2->arguments = arguments2;
    c2->commandName = *commandName2;

    // wc
    Value* commandName3 = new Value("wc");
    Command* c3 = new Command();
    c3->commandName = *commandName3;

    std::vector<Command> commands = {*c, *c2, *c3};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}

// cat < filenames.txt | grep aaa > filtered.txt
Program generatePipeWithRedirections() {
    // cat < filenames.txt
    Value* commandName = new Value("cat");
    Value *in = new Value("filenames.txt");
    std::vector<Value> ins = {*in};

    Command* c = new Command();
    c->inputFile = ins;
    c->commandName = *commandName;

    // grep aaa > filtered.txt
    Value* commandName2 = new Value("grep");
    Value *arg2 = new Value("aaa");
    std::vector<Value> arguments2 = {*arg2};
    Value *out2 = new Value("filtered.txt");
    std::vector<Value> outs2 = {*out2};

    Command* c2 = new Command();
    c2->arguments = arguments2;
    c2->commandName = *commandName2;
    c2->outputFile = outs2;

    std::vector<Command> commands = {*c, *c2};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}

Program generatePipeWithRedirections_NoPointers() {
    // cat < filenames.txt
    Value commandName = Value("cat");
    Value in = Value("filenames.txt");
    std::vector<Value> ins = {in};

    Command c = Command();
    c.inputFile = ins;
    c.commandName = commandName;

    // grep aaa > filtered.txt
    Value commandName2 = Value("grep");
    Value arg2 = Value("aaa");
    std::vector<Value> arguments2 = {arg2};
    Value out2 = Value("filtered.txt");
    std::vector<Value> outs2 = {out2};

    Command c2 = Command();
    c2.arguments = arguments2;
    c2.commandName = commandName2;
    c2.outputFile = outs2;

    std::vector<Command> commands = {c, c2};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}



// cat < filenames.txt > outfilenames.txt | grep aaa
Program generatePipeWithRedirections2() {
    // cat < filenames.txt > outfilenames.txt
    Value commandName = Value("cat");
    Value in = Value("filenames.txt");
    Value out = Value("outfilenames.txt");
    std::vector<Value> ins = {in};
    std::vector<Value> outs = {out};

    Command c = Command();
    c.inputFile = ins;
    c.outputFile = outs;
    c.commandName = commandName;

    // grep aaa
    Value commandName2 = Value("grep");
    Value arg2 = Value("aaa");
    std::vector<Value> arguments2 = {arg2};

    Command c2 = Command();
    c2.arguments = arguments2;
    c2.commandName = commandName2;

    std::vector<Command> commands = {c, c2};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}

// cat < filenames.txt > outfilenames.txt | grep aaa <  in2.txt
Program generatePipeWithRedirections3() {
    // cat < filenames.txt > outfilenames.txt
    Value commandName = Value("cat");
    Value in = Value("filenames.txt");
    Value out = Value("outfilenames.txt");
    std::vector<Value> ins = {in};
    std::vector<Value> outs = {out};

    Command c = Command();
    c.inputFile = ins;
    c.outputFile = outs;
    c.commandName = commandName;

    // grep aaa  <  in2.txt
    Value commandName2 = Value("grep");
    Value arg2 = Value("aaa");
    std::vector<Value> arguments2 = {arg2};
    Value out2 = Value("in2.txt");
    std::vector<Value> outs2 = {out2};

    Command c2 = Command();
    c2.arguments = arguments2;
    c2.commandName = commandName2;
    c2.outputFile = outs2;

    std::vector<Command> commands = {c, c2};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}
