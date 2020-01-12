
#include <stdexcept>
#include "Program.h"

std::string Program::execute(Context * context) {
    std::string out;
    for(auto varpip: this->varpips){
        out += varpip->execute(context);
    }
    return out;
}
