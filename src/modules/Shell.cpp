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
        std::cout << "$" << context.getWorkingDirectory() << " ";
        std::getline(std::cin, input);
        Program * program = parse(input);
        // parse input and start execution
        if(program){
            std::cout << input;
//            std::cerr << "Starting program..." << std::endl;
            std::cout << program->execute(&context) << std::endl;
        }
//        throw std::runtime_error("TODO: Shell::start");
    }
    std::cout << "Exiting...\n";
}
