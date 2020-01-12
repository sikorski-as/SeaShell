//
// Created by shakandrew on 12.01.2020.
//
#include "structures/Program.h"
#include "parser.hpp"

int main() {
    try {
        Program * root = parse(" words");
        root = parse("sleep 4");
        root = parse("kek = \"am am!\" ");
    } catch (std::exception &ex) {
        cout << "Exception found : " << ex.what() << endl;
    }
    return 0;
}