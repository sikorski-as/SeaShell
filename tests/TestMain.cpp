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

    // Test the West
    Program redirections_nopointers = generatePipeWithRedirections_NoPointers();
    Program redirection2_pointers = generatePipeWithRedirections2_Pointers();

    // Errors
    Program assignmentFailed = variableAssignementFail();
    Program assignmentFailedEchoSuccess = variableAssignementFailedBeforeSuccessfulInstr();
    Program assignmentFailedEchoFailed = failedVariableAssignementEchoed();
    Program cdFailed = cdToNonExistingFolder();

    // Example execution here (write your tests here)
    Context context;
    // std::cout<<"--- Pipe 1 result: "<<pipe1.execute(&context)<<std::endl;
    // std::cout<<"--- Pipe 2 result: "<<pipe2.execute(&context)<<std::endl;
    // std::cout<<"--- Pipe 3 result: "<<pipe3.execute(&context)<<std::endl;
    // std::cout<<"--- InRedir result: "<<inRedirection.execute(&context)<<std::endl;
    // std::cout<<"--- OutRedir result: "<<outRedirection.execute(&context)<<std::endl; */
    // std::cout<<"--- BothwaysRedir result: "<<redirection.execute(&context)<<std::endl;
    // std::cout<<"--- BothwaysRedirNoPointers result: "<<redirections_nopointers.execute(&context)<<std::endl;
//    std::cout<<"--- Redirection2 result: "<<redirection2.execute(&context)<<std::endl;
    // std::cout<<"--- Redirection2 result: "<<redirection2_pointers.execute(&context)<<std::endl;

    // Automatic Context tests
    testContextNoReplecement();
    testContextNormalReplacements();
    testEscapedDollarInText();
    testEscapedDollarInVariable();
    testSingleDollars();
    testNonExistingVariables();
    testContextNormalReplacements2();

    return 0;
}