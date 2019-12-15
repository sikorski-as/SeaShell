#include "PipeTests.h"

// echo "a bb" | wc
Program generateSimplePipe() {
    // echo "a bb"
    Identifier* echo = new Identifier("echo");
    std::vector<Node*> echoArguments;
    Identifier* arg = new Identifier("\"a bb\"");
    echoArguments.push_back(arg);
    Command* echoCommand = new Command(echo, echoArguments);

    // wc
    Identifier* wc = new Identifier("wc");
    std::vector<Node*> wcArguments;
    Command* wcCommand = new Command(wc, wcArguments);

    // pipe
    std::vector<Node*> pipes;
    pipes.push_back(echoCommand);
    pipes.push_back(wcCommand);
    PipeExpr* pipe = new PipeExpr(pipes);

    std::vector<Node*> programCommands;
    programCommands.push_back(pipe);
    return Program(programCommands);
}

// cat in.txt | grep aaa | wc
Program generateManyPipes() {
    // cat in.txt
    Identifier* cat = new Identifier("cat");
    std::vector<Node*> catArguments;
    Identifier* arg = new Identifier("in.txt");
    catArguments.push_back(arg);
    Command* catCommand = new Command(cat, catArguments);

    // grep aaa
    Identifier* grep = new Identifier("grep");
    std::vector<Node*> grepArguments;
    Identifier* grepArg = new Identifier("aaa");
    grepArguments.push_back(grepArg);
    Command* grepCommand = new Command(grep, grepArguments);

    // wc
    Identifier* wc = new Identifier("wc");
    std::vector<Node*> wcArguments;
    Command* wcCommand = new Command(wc, wcArguments);

    // pipe
    std::vector<Node*> pipes;
    pipes.push_back(catCommand);
    pipes.push_back(grepCommand);
    pipes.push_back(wcCommand);
    PipeExpr* pipe = new PipeExpr(pipes);

    std::vector<Node*> programCommands;
    programCommands.push_back(pipe);
    return Program(programCommands);
}

// cat < filenames.txt | grep aaa > filtered.txt
Program generatePipeWithRedirections() {
    // cat in.txt
    Identifier* cat = new Identifier("cat");
    std::vector<Node*> catArguments;
    Command* catCommand = new Command(cat, catArguments);
    Identifier* in = new Identifier("filenames.txt");
    RedirectionExpr* catRedirection = new RedirectionExpr(catCommand, in, nullptr);

    // grep aaa
    Identifier* grep = new Identifier("grep");
    std::vector<Node*> grepArguments;
    Identifier* grepArg = new Identifier("aaa");
    grepArguments.push_back(grepArg);
    Command* grepCommand = new Command(grep, grepArguments);
    Identifier* out = new Identifier("filtered.txt");
    RedirectionExpr* grepRedirection = new RedirectionExpr(grepCommand, nullptr, out);

    // pipe
    std::vector<Node*> pipes;
    pipes.push_back(catRedirection);
    pipes.push_back(grepRedirection);
    PipeExpr* pipe = new PipeExpr(pipes);

    std::vector<Node*> programCommands;
    programCommands.push_back(pipe);
    return Program(programCommands);
}