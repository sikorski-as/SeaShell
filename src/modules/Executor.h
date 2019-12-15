#ifndef UXP_EXECUTOR_H
#define UXP_EXECUTOR_H


#include "../structures/Program.h"
#include "../structures/VariableAssignment.h"
#include "Context.h"
#include "../../tests/TestInclude.h" // TODO do przeniesienia

class Executor {
    bool running = true;
    std::string EMPTY_STRING = "";
    Context context;
public:
    bool isRunning();
    void execute(Program&);
    std::string executeProgram(Program&);
    std::string executeVariableAssignment(VariableAssignment*);
    std::string executeCommand(Command*);
    std::string executeRedirectionExpression(RedirectionExpr*);
    std::string executePipeExpression(PipeExpr*);
    std::string executeBackTickExpression(BackTickExpr*);
};


#endif //UXP_EXECUTOR_H
