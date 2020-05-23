#ifndef CONTEXT_TESTS_H
#define CONTEXT_TESTS_H

#include "../src/modules/Context.h"
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

void testContextNoReplecement();
void testContextNormalReplacements();
void testEscapedDollarInText();
void testEscapedDollarInVariable();
void testSingleDollars();
void testNonExistingVariables();
void testContextNormalReplacements2();

// test single quotes
void testTextInSingleQuotes(); // 'test' -> test
void testSingleQuotesInTheMiddle(); // te'st' -> test
void testVariableInSingleQuotes(); // '$a' - > $a
void testReturnCode(); // $? -> 0
void testVariableAndTextInSingleQuotes(); // '$a ss' $a - > $a ss b

#endif