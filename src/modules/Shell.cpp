#include "Shell.h"
#include "Context.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include "../parser.hpp"

void Shell::start() {
    Context context;
    while(context.isRunning()){
        std::string input;
        std::cout << "$" << context.getWorkingDirectory() << std::flush;
        std::getline(std::cin, input);
        Program * program = parse(input);
        if(program){
            std::cout << program->execute(&context) << std::endl;
        }
    }
    std::cout << "Exiting...\n";
}
