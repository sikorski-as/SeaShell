#include "ErrorTests.h"

// 123local=host;
Program variableAssignemntFail() {
    Value name = Value("123local");
    Value newValue = Value("host");

    Variable* v = new Variable(name, newValue);

    std::vector<VarPip *> varpips = {v};
    Program p = Program();
    p.varpips = varpips;
    return p;
}

//123local=host;echo "test";
Program variableAssignemntFailedBeforeSuccessfulInstr() {
    //123local=host;
    Value varName = Value("123local");
    Value newValue = Value("host");
    Variable* v = new Variable(varName, newValue);

    //echo "test"
    Value commandName = Value("echo");
    Value name = Value("test");
    std::vector<Value> arguments = {name};
    Command c = Command();
    c.commandName = commandName;
    c.arguments = arguments;
    std::vector<Command> commands = {c};
    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {v, pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}

//123local=host;echo "$123local";
Program failedVariableAssignmentEchoed() {
    //123local=host;
    Value varName = Value("123local");
    Value newValue = Value("host");
    Variable* v = new Variable(varName, newValue);

    //echo "$123local"
    Value commandName = Value("echo");
    Value name = Value("$123local");
    std::vector<Value> arguments = {name};
    Command c = Command();
    c.commandName = commandName;
    c.arguments = arguments;
    std::vector<Command> commands = {c};
    Pipeline* pipe = new Pipeline(commands);

    std::vector<VarPip *> varpips = {v, pipe};
    Program p = Program();
    p.varpips = varpips;
    return p;
}

//cd nonExistingFolder
Program cdToNonExistingFolder() {
    Value commandName = Value("cd");
    Value name = Value("nonExistingFolder");
    std::vector<Value> arguments = {name};
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