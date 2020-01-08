#ifndef UXP_PROGRAM_H
#define UXP_PROGRAM_H


#include <vector>
#include "../modules/Context.h"
#include "VarPip.h"

class Program {
public:
    std::vector<VarPip *> varpips;
    std::string execute(Context *);
};


#endif //UXP_PROGRAM_H
