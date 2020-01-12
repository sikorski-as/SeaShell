#ifndef ECHO_TESTS_H
#define ECHO_TESTS_H

#include "TestInclude.h"

Program generateSimpleEcho(std::string echoArg = "msg");
Program generateEchoSystemVariable();
Program generateEchoSystemManyVariable();

#endif