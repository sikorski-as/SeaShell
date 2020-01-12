#include "BackTickExprTests.h"

// `echo pwd`
Program generateSimpleBackTick() {

    Program echoPwdProgram = generateSimpleEcho("pwd");

    Value commandName = Value(&echoPwdProgram);
   
    Command c = Command();
    c.commandName = commandName;
    std::vector<Command> commands = {c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}

// `echo "echo test"`
Program generateSimpleBackTick2() {
    Program echoPwdProgram = generateSimpleEcho("echo test");

    Value commandName = Value(&echoPwdProgram);
   
    Command c = Command();
    c.commandName = commandName;
    std::vector<Command> commands = {c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}

// `echo "echo"` test
Program generateBackTickWithArguments() {
    Program echoPwdProgram = generateSimpleEcho("echo");

    Value commandName = Value(&echoPwdProgram);
    Value argName = Value("test");
    std::vector<Value> arguments = {argName};
    Command c = Command();
    c.commandName = commandName;
    c.arguments = arguments;
    std::vector<Command> commands = {c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}

// `echo echo a bb` | wc
Program backTickInSimplePipe() {
    // echo "a bb"
    Program echoPwdProgram = generateSimpleEcho(" echo a bb");
    Value commandName = Value(&echoPwdProgram);
    Command c = Command();
    c.commandName = commandName;

    //wc
    Value commandName2 = Value("wc");
    Command c2 = Command();
    c2.commandName = commandName2;

    std::vector<Command> commands = {c, c2};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}

// cat a.txt | `echo grep u | cat` | wc
// w a.txt jest dupa
// oczekiwany output to: 
//      1       1       5
Program pipedBackTickInPipe() {
    // cat in.txt
    Value commandName = Value("cat");
    Value arg = Value("a.txt");
    std::vector<Value> arguments = {arg};
    Command c = Command();
    c.arguments = arguments;
    c.commandName = commandName;

    //`echo grep u | cat`
    Program backTickProgram = Program();

        // echo grep u
        Value backTickCommandName = Value("echo");
        Value backTickArgname1 = Value("grep");
        Value backTickArgname2 = Value("u");
        std::vector<Value> backTickArguments = {backTickArgname1, backTickArgname2};
        Command backTickCommand1 = Command();
        backTickCommand1.arguments = backTickArguments;
        backTickCommand1.commandName = backTickCommandName;

        //wc
        Value backTickCommandName2 = Value("wc");
        Command backTickCommand2 = Command();
        backTickCommand2.commandName = backTickCommandName2;

        // |
        std::vector<Command> backTickCommands = {backTickCommand1, backTickCommand2};
        Pipeline* backTickPipe = new Pipeline(backTickCommands);
        std::vector<VarPip *> backTickVarpips = {backTickPipe};
        backTickProgram.varpips = backTickVarpips;

    Value commandName2 = Value(&backTickProgram);
    Command c2 = Command();
    c2.commandName = commandName2;

    // wc
    Value commandName3 = Value("wc");
    Command c3 = Command();
    c3.commandName = commandName3;

    std::vector<Command> commands = {c, c2, c3};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}

Program backTickWithVariables() {
    
}


// lolek=1234; echo `lolek=5678; echo $lolek` $lolek
// wypisuje: 5678 1234

