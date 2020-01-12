#include "Signals.h"
#include <csignal>
#include <sys/types.h>
#include <vector>

std::vector<pid_t> childrenPids;

void signalHandler(int signum){
    if(!childrenPids.empty()){
        for(auto pid: childrenPids){
            kill(pid, signum);
        }
        childrenPids.clear();
    }
}