#include "modules/Shell.h"
#include "modules/Signals.h"
#include <csignal>

int main() {
    signal(SIGINT, signalHandler);
    signal(SIGQUIT, signalHandler);

    Shell().start();
    return 0;
}