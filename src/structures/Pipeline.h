#ifndef UXP_PIPELINE_H
#define UXP_PIPELINE_H

#include <vector>
#include <string>
#include "Command.h"
#include "../modules/Context.h"

class Pipeline : public VarPip{
public:
    std::vector<Command> commands;

    Pipeline(const Pipeline &) = default;
    explicit Pipeline(std::vector<Command>);

    std::string execute(Context *) override ;
    bool isEqual(VarPip*);
};


#endif //UXP_PIPELINE_H
