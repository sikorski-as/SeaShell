#include "Shell.h"
#include "Context.h"
#include <iostream>
#include <stdexcept>
#include <string>

void Shell::start() {
    Context context;
    while(context.isRunning()){
        std::string input;
        std::getline(std::cin, input);

        // parse input and start execution
        throw std::runtime_error("TODO: Shell::start");
    }
    std::cout << "Exiting...\n";
}
