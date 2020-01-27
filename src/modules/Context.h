#ifndef UXP_CONTEXT_H
#define UXP_CONTEXT_H

#include <map>
#include <string>
#include <vector>

class Context {
    std::map<std::string, std::string> localVars;
    bool running = true;
    int lastReturnCode = 0;
    void split(const std::string& str, std::vector<std::string> &cont,
               const std::string& delimss);
public:
    bool isRunning();
    void stop();

    void setLastReturnCode(int);
    int getLastReturnCode();
    
    void exportVariable(std::string key, std::string value);
    void setVariable(std::string key, std::string value);
    std::string getVariable(std::string key);

    std::string resolveVariables(std::string s);

    std::string getWorkingDirectory();
    void setWorkingDirectory(std::string);
};


#endif //UXP_CONTEXT_H
