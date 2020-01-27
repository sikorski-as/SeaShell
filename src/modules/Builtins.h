#ifndef UXP_BUILTINS_H
#define UXP_BUILTINS_H

#include <string>
#include "../structures/Command.h"
#include "Context.h"

std::string builtin(Command &, Context*, bool);
bool isBuiltin(std::string);

#endif //UXP_BUILTINS_H
