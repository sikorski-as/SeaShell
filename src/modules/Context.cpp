#include "Context.h"
#include <stdlib.h>
#include <iostream>
#include <ctype.h>

void Context::setVariable(std::string key, std::string value) {
    this->localVars[key] = value;
}

void Context::exportVariable(std::string key, std::string value) {
    this->setVariable(key, value);
    setenv(key.c_str(), value.c_str(), true);
}

std::string Context::getVariable(std::string key) {
    // check in local
    auto it = this->localVars.find(key);
    if (it != localVars.end()) {
        return it->second;
    }
    // check in global
    char *envVal = getenv((char *) key.c_str());
    if (envVal != nullptr) {
        return std::string(envVal);
    }
    // not found
    return "";
}

std::string Context::resolveVariables(std::string s) {
    auto indx =  s.find('$', 0);
    while(indx != std::string::npos) {
        if(indx == 0 || s.at(indx-1) != '\\') { // this is not escaped
            bool search = true;
            bool hasName = true;
            int pos = -1;
            for(int i = indx + 1; i < s.length() && search; i++) {
                char c = s.at(i);
                if (!isalnum(c) &&  c!='_') {
                    if(i == indx+1)
                        hasName = false;
                    search = false;
                    pos = i;
                }
            }
            if(pos == -1)
                pos = s.length();
            if(hasName && indx + 1 < s.length()) { // do a replacement if there is name after $
                std::string variableName = s.substr(indx+1, pos-indx-1);
                std::string resolvedVariable = this->getVariable(variableName);
                s.replace(indx, pos-indx, resolvedVariable);
                indx = s.find('$', indx + resolvedVariable.length());
            } else
                indx = s.find('$', indx + 1);
        } else {
            if(s.at(indx-1) == '\\') { // delete replacement
                s.replace(indx-1, 1, "");
            }
            indx = s.find('$', indx + 1);
        }
        
    }
    return s;
}