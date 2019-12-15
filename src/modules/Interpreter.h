#ifndef UXP_INTERPRETER_H
#define UXP_INTERPRETER_H


#include "../structures/Program.h"
#include <string>

class Interpreter {
public:
    Program getTree();

    void feed(std::string&);
};


#endif //UXP_INTERPRETER_H
