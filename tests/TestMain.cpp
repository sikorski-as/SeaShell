#include "AllTests.h"
#include "../src/modules/Executor.h"

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

    auto ex = Executor();
    ex.execute(assignment);

    return 0;
}