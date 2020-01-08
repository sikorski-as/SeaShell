#ifndef ASSIGNABLE_H
#define ASSIGNABLE_H

#include "Node.h"
#include <string>
class Assignable : public Node {
    public:
        virtual NodeType getType() = 0;
        virtual std::string toString() = 0;
        ~Assignable(){};
};

#endif