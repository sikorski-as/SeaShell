
#include <iostream>
#include "Executor.h"

bool Executor::isRunning() {
    return this->running;
}

void Executor::execute(Program& program) {
    std::cout << "Executing!\n";
    this->running = false;
}
