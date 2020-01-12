#include "ContextTests.h"

void testContextNoReplecement(){
    Context c = Context();
    std::string result = c.resolveVariables("test no replacement");
    assert(result.compare("test no replacement") == 0);
}

void testContextNormalReplacements(){
    Context c = Context();
    c.setVariable("a", "TEST_A");
    c.setVariable("b_b", "TEST_B");
    c.setVariable("cCcCc", "c");

    std::string result = c.resolveVariables("$a $b_b$cCcCc done");
    assert(result.compare("TEST_A TEST_Bc done") == 0);
}

void testContextNormalReplacements2(){
    Context c = Context();
    c.setVariable("a", "b");

    std::string result = c.resolveVariables("$a");
    assert(result.compare("b") == 0);
}

void testEscapedDollarInText(){
    Context c = Context();
    std::string result = c.resolveVariables("\\$a");
    assert(result.compare("$a") == 0);
}

void testEscapedDollarInVariable(){
    Context c = Context();
    c.setVariable("a", "$");
    std::string result = c.resolveVariables("$a");
    assert(result.compare("$") == 0);
}

void testSingleDollars(){
    Context c = Context();
    std::string result = c.resolveVariables("$");
    assert(result.compare("$") == 0);
    result = c.resolveVariables("$ %");
    assert(result.compare("$ %") == 0);
}

void testNonExistingVariables(){
    Context c = Context();
    c.setVariable("bag", "bag");
    std::string result = c.resolveVariables("$b");
    assert(result.compare("") == 0);
}

// do rozwazenia:
// a = b\$; echo $a
// echo '$a'