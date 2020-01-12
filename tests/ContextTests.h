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

#endif