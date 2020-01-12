#include "AllTests.h"
// #include "../src/modules/Executor.h"
// #include "../src/modules/Cleaner.h"
#include <iostream>

int main() {
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
    Program simpleBackTickPwd = generateSimpleBackTick();


    // Errors
    Program assignmentFailed = variableAssignementFail();
    Program assignmentFailedEchoSuccess = variableAssignementFailedBeforeSuccessfulInstr();
    Program assignmentFailedEchoFailed = failedVariableAssignementEchoed();
    Program cdFailed = cdToNonExistingFolder();

//     auto ex = Executor();
//     ex.execute(assignment);

// // for testing assigning variable call to another variable TODO make test for it
//     // std::string variableName = "local2";
//     // VariableCall vCall = VariableCall("local");
//     // VariableAssignment varAssignment = VariableAssignment(variableName, &vCall);
//     // std::vector<Node*> commands;
//     // commands.push_back(&varAssignment);
//     // Program p = Program(commands);
//     // ex.execute(p);


//     Cleaner cleaner = Cleaner();
//     cleaner.clean(&pwd);
//     cleaner.clean(&cd);
//     cleaner.clean(&echo);
//     cleaner.clean(&echo2);
//     cleaner.clean(&echo3);
//     cleaner.clean(&assignment);
//     cleaner.clean(&exported);
//     cleaner.clean(&pipe1);
//     cleaner.clean(&pipe2);
//     cleaner.clean(&pipe3);
//     cleaner.clean(&outRedirection);
//     cleaner.clean(&inRedirection);
//     cleaner.clean(&redirection);

    // Context tests
    testContextNoReplecement();
    testContextNormalReplacements();
    testEscapedDollarInText();
    testEscapedDollarInVariable();
    testSingleDollars();
    testNonExistingVariables();

    return 0;
}