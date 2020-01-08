#include <iostream>
#include "modules/Shell.h"
#include "parser.hpp"

int main() {
    Program * some = parse("Am am am");
    some = parse("a > o.txt < i.txt");
    some = parse("mkdir testdir;");
    some = parse("lolek = Bolek");
    some = parse("echo $Lolek > a.txt");
    some = parse("echo `cat some.c`");
    cout << "LOXL";
//    auto sh = Shell();
//    sh.start();
}