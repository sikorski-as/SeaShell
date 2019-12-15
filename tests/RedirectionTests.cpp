#include "RedirectionTests.h"

// ls > out.txt
Program generateOutputRedirection() {
    // ls
    Identifier commandName = Identifier("ls");
    std::vector<Node*> arguments;
    Command c = Command(&commandName, arguments);

    // ls as a part of redirection expr
    Identifier out = Identifier("out.txt");
    RedirectionExpr r = RedirectionExpr(&c, nullptr, &out);

    std::vector<Node*> commands;
    commands.push_back(&r);
    return Program(commands);
}

// cd < in.txt
Program generateInputRedirection() {
    // cd
    Identifier commandName = Identifier("cd");
    std::vector<Node*> arguments;
    Command c = Command(&commandName, arguments);

    // cd as a part of redirection expr
    Identifier in = Identifier("in.txt");
    RedirectionExpr r = RedirectionExpr(&c, &in, nullptr);

    std::vector<Node*> commands;
    commands.push_back(&r);
    return Program(commands);
}

// grep < in.txt >out.txt aaa
Program generateBothWayRedirection() {
    // grep
    Identifier commandName = Identifier("grep");
    std::vector<Node*> arguments;
    Identifier arg = Identifier("aaa");
    arguments.push_back(&arg);
    Command c = Command(&commandName, arguments);

    // grep as a part of redirection expr
    Identifier in = Identifier("in.txt");
    Identifier out = Identifier("out.txt");
    RedirectionExpr r = RedirectionExpr(&c, &in, &out);

    std::vector<Node*> commands;
    commands.push_back(&r);
    return Program(commands);
}