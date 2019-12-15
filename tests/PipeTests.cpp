#include "PipeTests.h"

// echo "a bb" | wc
Program generateSimplePipe() {
    // echo "a bb"
    Identifier echo = Identifier("echo");
    std::vector<Node*> echoArguments;
    Identifier arg = Identifier("\"a bb\"");
    echoArguments.push_back(&arg);
    Command echoCommand = Command(&echo, echoArguments);

    // wc
    Identifier wc = Identifier("wc");
    std::vector<Node*> wcArguments;
    Command wcCommand = Command(&wc, wcArguments);

    // pipe
    std::vector<Node*> pipes;
    pipes.push_back(&echoCommand);
    pipes.push_back(&wcCommand);
    PipeExpr pipe = PipeExpr(pipes);

    std::vector<Node*> programCommands;
    programCommands.push_back(&pipe);
    return Program(programCommands);
}

// cat in.txt | grep aaa | wc
Program generateManyPipes() {
    // cat in.txt
    Identifier cat = Identifier("cat");
    std::vector<Node*> catArguments;
    Identifier arg = Identifier("in.txt");
    catArguments.push_back(&arg);
    Command catCommand = Command(&cat, catArguments);

    // grep aaa
    Identifier grep = Identifier("grep");
    std::vector<Node*> grepArguments;
    Identifier grepArg = Identifier("aaa");
    grepArguments.push_back(&grepArg);
    Command grepCommand = Command(&grep, grepArguments);

    // wc
    Identifier wc = Identifier("wc");
    std::vector<Node*> wcArguments;
    Command wcCommand = Command(&wc, wcArguments);

    // pipe
    std::vector<Node*> pipes;
    pipes.push_back(&catCommand);
    pipes.push_back(&grepCommand);
    pipes.push_back(&wcCommand);
    PipeExpr pipe = PipeExpr(pipes);

    std::vector<Node*> programCommands;
    programCommands.push_back(&pipe);
    return Program(programCommands);
}

// cat < filenames.txt | grep aaa > filtered.txt
Program generatePipeWithRedirections() {
    // cat in.txt
    Identifier cat = Identifier("cat");
    std::vector<Node*> catArguments;
    Command catCommand = Command(&cat, catArguments);
    Identifier in = Identifier("filenames.txt");
    RedirectionExpr catRedirection = RedirectionExpr(&catCommand, &in, nullptr);

    // grep aaa
    Identifier grep = Identifier("grep");
    std::vector<Node*> grepArguments;
    Identifier grepArg = Identifier("aaa");
    grepArguments.push_back(&grepArg);
    Command grepCommand = Command(&grep, grepArguments);
    Identifier out = Identifier("filtered.txt");
    RedirectionExpr grepRedirection = RedirectionExpr(&grepCommand, nullptr, &out);

    // pipe
    std::vector<Node*> pipes;
    pipes.push_back(&catRedirection);
    pipes.push_back(&grepRedirection);
    PipeExpr pipe = PipeExpr(pipes);

    std::vector<Node*> programCommands;
    programCommands.push_back(&pipe);
    return Program(programCommands);
}