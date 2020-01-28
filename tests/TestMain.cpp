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
    Program outRedirection = generateOutputRedirection();
    Program inRedirection = generateInputRedirection();
    Program redirection = generateBothWayRedirection();
    Program redirection2 = generatePipeWithRedirections2();
    Program redirection3 = generatePipeWithRedirections3();

    // Errors
    Program cdFailed = cdToNonExistingFolder();

    // Example execution here (write your tests here)
    Context context;

//    std::cout << "-- Simple echo result: " << echo.execute(&context, false) << std::endl;
//    std::cout << "-- Simple echo result: " << pwd.execute(&context, false) << std::endl;
//    std::cout << "-- Simple echo result: " << cd.execute(&context, false) << std::endl;
//    std::cout << "-- Simple echo result: " << echo2.execute(&context, false) << std::endl;
//    std::cout << "-- Simple echo result: " << echo3.execute(&context, false) << std::endl;
//    std::cout << "-- Simple echo result: " << assignment.execute(&context, false) << std::endl;
//    std::cout << exported.execute(&context, false) << std::endl;
//    std::cout << pipe1.execute(&context, false) << std::endl;
//    std::cout << pipe2.execute(&context, false) << std::endl;
//    std::cout << pipe3.execute(&context, false) << std::endl;
//    std::cout << outRedirection.execute(&context, false) << std::endl;
//    std::cout << inRedirection.execute(&context, false) << std::endl;
//    std::cout << redirection.execute(&context, false) << std::endl;
//    std::cout << redirection2.execute(&context, false) << std::endl;
//    std::cout << redirection3.execute(&context, false) << std::endl;


    // Automatic Context tests
    testContextNoReplecement();
    testContextNormalReplacements();
    testEscapedDollarInText();
    testEscapedDollarInVariable();
    testSingleDollars();
    testNonExistingVariables();
    testContextNormalReplacements2();
    testTextInSingleQuotes(); // 'test' -> test
    testSingleQuotesInTheMiddle(); // te'st' -> test
    testVariableInSingleQuotes(); // '$a' - > $a
    testReturnCode(); // $? -> 0
    testVariableAndTextInSingleQuotes(); // '$a ss' $a - > $a ss b

//    // Automatic Parser Tests
    testParserGenerateSimpleCd();
    testParserGenerateSimpleEcho();
    testParserGenerateEchoSystemVariable();
    testParserGenerateEchoSystemManyVariable();
    testParserGenerateSimpleExport();
    testParserGenerateSimplePipe();
    testParserGenerateManyPipes();
    testParserGeneratePipeWithRedirections();
    testParserGeneratePipeWithRedirections2();
    testParserGeneratePipeWithRedirections3();
    testParserGenerateSimplePwd();
    testParserGenerateOutputRedirection();
    testParserGenerateInputRedirection();
    testParserGenerateBothWayRedirection();
    testParserGenerateSimpleAssignment();

    return 0;
}