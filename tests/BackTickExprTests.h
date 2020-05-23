#ifndef BACKTICK_TESTS_H
#define BACKTICK_TESTS_H

#include "TestInclude.h"

Program generateSimpleBackTick();
Program generateSimpleBackTick2();
Program generateBackTickWithArguments();
Program backTickInSimplePipe();
Program pipedBackTickInPipe();
Program backTickWithVariables();

Program * generateEcho(std::string echoArg);

void testParserGenerateSimpleBackTick();
void testParserGenerateSimpleBackTick2();
void testParserGenerateBackTickWithArguments();
void testParserBackTickInSimplePipe();
void testParserPipedBackTickInPipe();
void testParserBackTickWithVariables();

#endif