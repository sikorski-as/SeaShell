#include "EchoTests.h"

// echo "msg"
Program generateSimpleEcho() {
    Identifier* commandName = new Identifier("echo");
    std::vector<Node*> arguments;
    Identifier* name = new Identifier("msg");
    arguments.push_back(name);
    Command* c = new Command(commandName, arguments);
    std::vector<Node*> commands;
    commands.push_back(c);
    return Program(commands);
}

// echo "$PATH"
Program generateEchoSystemVariable() {
    Identifier* commandName = new Identifier("echo");
    std::vector<Node*> arguments;
    Identifier* name = new Identifier("$PATH");
    arguments.push_back(name);
    Command* c = new Command(commandName, arguments);
    std::vector<Node*> commands;
    commands.push_back(c);
    return Program(commands);
}

// echo "$PATH $PATH"
Program generateEchoSystemManyVariable() {
    Identifier* commandName = new Identifier("echo");
    std::vector<Node*> arguments;
    Identifier* name = new Identifier("$PATH $PATH");
    arguments.push_back(name);
    Command* c = new Command(commandName, arguments);
    std::vector<Node*> commands;
    commands.push_back(c);
    return Program(commands);
}