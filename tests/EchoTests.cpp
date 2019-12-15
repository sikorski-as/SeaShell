#include "EchoTests.h"

// echo "msg"
Program generateSimpleEcho() {
    Identifier commandName = Identifier("echo");
    std::vector<Node*> arguments;
    Identifier name = Identifier("\"msg\"");
    arguments.push_back(&name);
    Command c = Command(&commandName, arguments);
    std::vector<Node*> commands;
    commands.push_back(&c);
    return Program(commands);
}

// echo "$PATH"
Program generateEchoSystemVariable() {
    Identifier commandName = Identifier("echo");
    std::vector<Node*> arguments;
    Identifier name = Identifier("\"$PATH\"");
    arguments.push_back(&name);
    Command c = Command(&commandName, arguments);
    std::vector<Node*> commands;
    commands.push_back(&c);
    return Program(commands);
}

// echo "$PATH $PATH"
Program generateEchoSystemManyVariable() {
    Identifier commandName = Identifier("echo");
    std::vector<Node*> arguments;
    Identifier name = Identifier("\"$PATH $PATH\"");
    arguments.push_back(&name);
    Command c = Command(&commandName, arguments);
    std::vector<Node*> commands;
    commands.push_back(&c);
    return Program(commands);
}