#ifndef NODE_H
#define NODE_H

#include "NodeType.h"

class Node {
    protected:
        NodeType type;
    public:
        virtual NodeType getType() = 0;
        ~Node(){};
};
#endif