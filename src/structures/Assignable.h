#ifndef ASSIGNABLE_H
#define ASSIGNABLE_H

#include "Node.h"

class Assignable : public Node {
    public:
        Assignable(/* args */);
        ~Assignable();
        NodeType getType(){return NodeType::NONE;}
};

#endif