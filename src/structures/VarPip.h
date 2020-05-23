#ifndef UXP_VARPIP_H
#define UXP_VARPIP_H

#include <string>
#include "../modules/Context.h"

class VarPip {
public:
    virtual std::string execute(Context *, bool backtick) = 0;
    virtual bool isEqual(VarPip *) = 0;
};


#endif //UXP_VARPIP_H
