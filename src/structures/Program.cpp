
#include <stdexcept>
#include <iostream>
#include "Program.h"

std::string Program::execute(Context *context) {
    std::string out;
    bool first = true;
    for (auto varpip: this->varpips) {
        auto output = varpip->execute(context);
        if (first) {
            out += output;
            first = false;

        } else {
            out += '\n' + varpip->execute(context);
        }
    }
    return out;
}
