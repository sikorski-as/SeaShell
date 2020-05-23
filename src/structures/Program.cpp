
#include <stdexcept>
#include <iostream>
#include "Program.h"

std::string Program::execute(Context *context, bool backtick) {
    std::string out;
    bool first = true;
    for (auto varpip: this->varpips) {
        auto output = varpip->execute(context, backtick);
        if(backtick){
            if (first) {
                out += output;
                first = false;

            } else {
                out += '\n' + output;
            }
        }
    }
    return out;
}

bool Program::isEqual(Program *p) {
    if(p->varpips.size() != this->varpips.size())
        return false;
    int i = 0;
    for(auto varpip: this->varpips) {
        if(!varpip->isEqual(p->varpips[i]))
            return false;
        i++;
    }
    return true;
}