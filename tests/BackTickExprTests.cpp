#include "BackTickExprTests.h"

// `echo pwd`
Program generateSimpleBackTick() {

    Program* echoPwdProgram = generateEcho("pwd");

    Value* commandName = new Value(echoPwdProgram);
   
    Command* c = new Command();
    c->commandName = *commandName;
    std::vector<Command> commands = {*c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return *p;
}

// `echo "echo test"`
Program generateSimpleBackTick2() {
    Program* echoPwdProgram = generateEcho("echo test");

    Value commandName = Value(echoPwdProgram);
   
    Command c = Command();
    c.commandName = commandName;
    std::vector<Command> commands = {c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}

Program * generateEcho(std::string echoArg) {
    Value* commandName = new Value("echo");
    Value* name = new Value(echoArg);
    std::vector<Value> arguments = {*name};

    Command* c = new Command();
    c->commandName = *commandName;
    c->arguments = arguments;

    std::vector<Command> commands = {*c};

    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {pipe};
    Program* p = new Program();
    p->varpips = varpips;
    return p;
}

// `echo "echo"` test
Program generateBackTickWithArguments() {
    Program* echoPwdProgram = generateEcho("echo");

    Value commandName = Value(echoPwdProgram);
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
    Program* echoPwdProgram = generateEcho(" echo a bb");
    Value commandName = Value(echoPwdProgram);
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

void testParserGenerateSimpleBackTick() {
    Program *p = parse("`echo pwd`");
    Program t = generateSimpleBackTick();
    assert(p->isEqual(&t));
}

void testParserGenerateSimpleBackTick2() {
    Program *p = parse("`echo \"echo test\"`");
    Program t = generateSimpleBackTick2();
    assert(p->isEqual(&t));
}

void testParserGenerateBackTickWithArguments() {
    Program *p = parse("`echo \"echo\"` test");
    Program t = generateBackTickWithArguments();
    assert(p->isEqual(&t));
}

void testParserBackTickInSimplePipe() {
    Program *p = parse("`echo echo a bb` | wc");
    Program t = backTickInSimplePipe();
    assert(p->isEqual(&t));
}

void testParserPipedBackTickInPipe() {
    Program *p = parse("cat a.txt | `echo grep u | cat` | wc");
    Program t = pipedBackTickInPipe();
    assert(p->isEqual(&t));
}
void testParserBackTickWithVariables();


// lolek=1234; echo `lolek=5678; echo $lolek` $lolek
// wypisuje: 5678 1234

