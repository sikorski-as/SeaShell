
#include <iostream>
#include "Executor.h"
#include "Context.h"

bool Executor::isRunning() {
    return this->running;
}

void Executor::execute(Program& program) {
    std::cout << "Executing!\n";

    Context c;
    c.exportVariable("lolek", "bolek");
    c.setVariable("piesek", "reksio");
    std::cout<<c.getVariable("lolek")<<std::endl;
    std::cout<<c.getVariable("piesek")<<std::endl;
    
    c.setVariable("lolek", "tola");
    std::cout<<c.getVariable("lolek")<<std::endl;

    c.exportVariable("lolek", "bolek2");
    std::cout<<c.getVariable("lolek")<<std::endl;

    std::cout<<c.getVariable("OLDPWD")<<std::endl;

    this->running = false;
}