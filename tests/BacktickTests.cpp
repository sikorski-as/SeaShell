
#include "BacktickTests.h"
#include "../src/structures/Identifier.h"
#include "../src/structures/Command.h"
#include "../src/structures/BackTickExpr.h"

// `echo cd` dest
Program generateSimpleBacktick() {
    // tworzy komendę wewnątrz back tick expression
    using Nodes = std::vector<Node*>;

    auto backTickExpression = new BackTickExpr(new Program(Nodes{
        new Command(new Identifier("echo"), Nodes{new Identifier("cd")})
    }));

    return Program(Nodes{
        new Command(backTickExpression, Nodes{new Identifier("dest")})
    });









//    Identifier *commandName = new Identifier("echo");
//    std::vector<Node *> arguments;
//    Identifier *folderName = new Identifier("cd");
//    arguments.push_back(folderName);
//
//    BackTickExpr* backtickExpression = new BackTickExpr()
//
//    // tworzy program WEWNĄTRZ back tick expression
//    Program *backTickProgram = new Program(
//                std::vector<Node*>{new Command(commandName, arguments)});
//
//    // tworzy program Z back tick expression
//    return Program(
//            std::vector<Node*>{new Command(
//                    new BackTickExpr(backTickProgram), new Identifier('dest')}
//                    )});
}