#ifndef NODE_H
#define NODE_H

#include "NodeType.h"

class Node {
    protected:
        NodeType type;
    public:
        NodeType getType(){return NodeType::NONE;}
        Node(/* args */);
        ~Node();
};
#endif