#include <iostream>
#include "structures/Node.h"

int main(){
    Node* n = new Node();
    std::cout << n->toString() << std::endl << *n << std::endl;
    return 0;
}