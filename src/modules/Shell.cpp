#include "Shell.h"
#include <iostream>
#include <stdexcept>
#include <string>

void Shell::start() {
    while(true){
        std::string input;
        std::getline(std::cin, input);
        // process input and start program

        std::runtime_error("TODO: Shell::start");
    }
    std::cout << "Exiting...\n";
}
