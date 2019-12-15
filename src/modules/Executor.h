#ifndef UXP_EXECUTOR_H
#define UXP_EXECUTOR_H


#include "../structures/Program.h"
#include "../structures/VariableAssignment.h"
#include "Context.h"

class Executor {
    bool running = true;
    Context context;
public:
    bool isRunning();
    void execute(Program&);
    void executeVariableAssignment(VariableAssignment*);
};


#endif //UXP_EXECUTOR_H
