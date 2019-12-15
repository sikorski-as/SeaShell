#ifndef ASSIGNABLE_H
#define ASSIGNABLE_H

#include "Node.h"

class Assignable : public Node {
    public:
        virtual NodeType getType() = 0;
        ~Assignable(){};
};

#endif