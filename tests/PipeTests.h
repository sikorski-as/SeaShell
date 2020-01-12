#ifndef PIPE_TESTS_H
#define PIPE_TESTS_H

#include "TestInclude.h"

Program generateSimplePipe();
Program generateManyPipes();
Program generatePipeWithRedirections();
Program generatePipeWithRedirections2();
Program generatePipeWithRedirections3();
Program generatePipeWithRedirections_NoPointers();
Program generatePipeWithRedirections2_Pointers();

void testParserGenerateSimplePipe();
void testParserGenerateManyPipes();
void testParserGeneratePipeWithRedirections();
void testParserGeneratePipeWithRedirections2();
void testParserGeneratePipeWithRedirections3();

#endif