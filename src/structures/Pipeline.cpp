
#include <stdexcept>
#include "Pipeline.h"

Pipeline::Pipeline(std::vector<Command> cmds)
: commands(cmds)
{}

std::string Pipeline::execute(Context *) {
    throw std::runtime_error("TODO: Pipeline::execute");
}
