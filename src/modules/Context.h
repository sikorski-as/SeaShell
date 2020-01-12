#ifndef UXP_CONTEXT_H
#define UXP_CONTEXT_H

#include <map>
#include <string>

class Context {
    std::map<std::string, std::string> localVars;
public:
    void exportVariable(std::string key, std::string value);
    void setVariable(std::string key, std::string value);
    std::string getVariable(std::string key);

    std::string resolveVariables(std::string s);

    std::string getWorkingDirectory();
    void setWorkingDirectory(std::string);
};


#endif //UXP_CONTEXT_H
