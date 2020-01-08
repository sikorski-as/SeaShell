

#include "Shell.h"
#include "Interpreter.h"
#include "Executor.h"
#include <iostream>
#include <string>

void Shell::start() {
    auto interpreter = Interpreter();
    auto executor = Executor();
    while(executor.isRunning()){
        std::string input;
        std::getline(std::cin, input);
        interpreter.feed(input);
        auto program = interpreter.getTree();
        executor.execute(program);
    }
    std::cout << "Exiting...\n";
}
