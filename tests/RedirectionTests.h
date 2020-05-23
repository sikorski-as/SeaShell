#ifndef REDIRECTION_TESTS_H
#define REDIRECTION_TESTS_H

#include "TestInclude.h"

Program generateOutputRedirection();
Program generateInputRedirection();
Program generateBothWayRedirection();

void testParserGenerateOutputRedirection();
void testParserGenerateInputRedirection();
void testParserGenerateBothWayRedirection();

#endif