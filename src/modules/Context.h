#ifndef UXP_CONTEXT_H
#define UXP_CONTEXT_H

#include <map>

class Context {
    std::map<std::string, std::string> localVars;
public:
    void exportVariable(std::string key, std::string value);
    void setVariable(std::string key, std::string value);
    std::string getVariable(std::string key);
};


#endif //UXP_CONTEXT_H
