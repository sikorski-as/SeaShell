#include "RedirectionTests.h"

// ls > out.txt
Program generateOutputRedirection() {
    // ls
    Identifier* commandName = new Identifier("ls");
    std::vector<Node*> arguments;
    Command* c = new Command(commandName, arguments);

    // ls as a part of redirection expr
    Identifier* out = new Identifier("out.txt");
    RedirectionExpr* r = new RedirectionExpr(c, nullptr, out);

    std::vector<Node*> commands;
    commands.push_back(r);
    return Program(commands);
}

// cd < in.txt
Program generateInputRedirection() {
    // cd
    Identifier* commandName = new Identifier("cd");
    std::vector<Node*> arguments;
    Command* c = new Command(commandName, arguments);

    // cd as a part of redirection expr
    Identifier* in = new Identifier("in.txt");
    RedirectionExpr* r = new RedirectionExpr(c, in, nullptr);

    std::vector<Node*> commands;
    commands.push_back(r);
    return Program(commands);
}

// grep < in.txt >out.txt aaa
Program generateBothWayRedirection() {
    // grep
    Identifier* commandName = new Identifier("grep");
    std::vector<Node*> arguments;
    Identifier* arg = new Identifier("aaa");
    arguments.push_back(arg);
    Command* c = new Command(commandName, arguments);

    // grep as a part of redirection expr
    Identifier* in = new Identifier("in.txt");
    Identifier* out = new Identifier("out.txt");
    RedirectionExpr* r = new RedirectionExpr(c, in, out);

    std::vector<Node*> commands;
    commands.push_back(r);
    return Program(commands);
}