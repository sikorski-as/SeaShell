#ifndef NODE_H
#define NODE_H

#include <string>
#include "NodeType.h"

class Node {
public:
    virtual std::string toString() const;

    ~Node() {};
};

std::ostream &operator<<(std::ostream &os, Node const &node);

#endif