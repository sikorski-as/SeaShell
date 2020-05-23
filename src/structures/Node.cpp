#include "Node.h"

#include <sstream> //for std::stringstream
#include <string>  //for std::string

std::string Node::toString() const {
    const void *address = static_cast<const void *>(this);
    std::stringstream ss;
    ss << address;
    std::string name = ss.str();

    return "<Node object at " + ss.str() + ">";
}

std::ostream &operator<<(std::ostream &os, Node const &node) {
    return os << node.toString();
}
