#ifndef NODE_H
#define NODE_H

#include "NodeType.h"
#include <string>

class Node {
    protected:
        NodeType type;
    public:
        virtual NodeType getType() = 0;
        virtual std::string toString() = 0;
        ~Node(){};
};
#endif