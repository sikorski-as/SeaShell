#include "AllTests.h"
#include <iostream>

int main() {
    // Working examples
    Program pwd = generateSimplePwd();
    Program cd = generateSimpleCd();
    Program echo = generateSimpleEcho();
    Program echo2 = generateEchoSystemVariable();
    Program echo3 = generateEchoSystemManyVariable();
    Program assignment = generateSimpleAssignment();
    Program exported = generateSimpleExport();
    Program pipe1 = generateSimplePipe();
    Program pipe2 = generateManyPipes();
    Program pipe3 = generatePipeWithRedirections();
    Program outRedirection =  generateOutputRedirection();
    Program inRedirection = generateInputRedirection();
    Program redirection = generateBothWayRedirection();
    Program redirection2 = generatePipeWithRedirections2();
    Program redirection3 = generatePipeWithRedirections3();
    Program simpleBackTickPwd = generateSimpleBackTick();
    Program simpleBackTick = generateSimpleBackTick2();
    Program simpleBackTickWithArguments = generateBackTickWithArguments();
    Program simpleBackTickInSimplePipe = backTickInSimplePipe();
    Program pipedBackTick = pipedBackTickInPipe();

    // Errors
    Program assignmentFailed = variableAssignementFail();
    Program assignmentFailedEchoSuccess = variableAssignementFailedBeforeSuccessfulInstr();
    Program assignmentFailedEchoFailed = failedVariableAssignementEchoed();
    Program cdFailed = cdToNonExistingFolder();

    // Example execution here (write your tests here)
    Context context;


    // Automatic Context tests
    testContextNoReplecement();
    testContextNormalReplacements();
    testEscapedDollarInText();
    testEscapedDollarInVariable();
    testSingleDollars();
    testNonExistingVariables();

    return 0;
}