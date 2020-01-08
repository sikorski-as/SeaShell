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

// a=b | wc | tee diag.txt
Program generateErroneousPipe() { // first doesn't write to stdout
    // a=b
    Identifier* echo = new Identifier("a=b");
    std::vector<Node*> echoArguments;
    /* Identifier* arg = new Identifier("\"a bb\"");
    echoArguments.push_back(arg); */
    Command* echoCommand = new Command(echo, echoArguments);

    // wc
    Identifier* wc = new Identifier("wc");
    std::vector<Node*> wcArguments;
    Command* wcCommand = new Command(wc, wcArguments);

    // tee
    Identifier* tee = new Identifier("tee");
    std::vector<Node*> teeArguments;
    Identifier* arg = new Identifier("diag.txt");
    teeArguments.push_back(arg);
    Command* teeCommand = new Command(tee, teeArguments);

    // pipe
    std::vector<Node*> pipes;
    pipes.push_back(echoCommand);
    pipes.push_back(teeCommand);
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