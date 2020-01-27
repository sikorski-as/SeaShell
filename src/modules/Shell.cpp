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
        std::cout << "\033[1;44;37mSeaShell\033[0;36m in: \033[0m" << context.getWorkingDirectory() << " $ " << std::flush;
        std::getline(std::cin, input);
        Program * program = parse(input);
        if(program){
            std::cout << program->execute(&context) << std::endl;

            int lastReturnCode = context.getLastReturnCode();
            if(lastReturnCode > 0) std::cerr << "Process finished with error code: "<<lastReturnCode<<std::endl;
        }
    }
    std::cout << "Exiting...\n";
}
