#ifndef UXP_EXECUTOR_H
#define UXP_EXECUTOR_H


#include "../structures/Program.h"

class Executor {
    bool running = true;
public:
    bool isRunning();
    void execute(Program&);
};


#endif //UXP_EXECUTOR_H
