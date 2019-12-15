#include "Context.h"
#include <stdlib.h>
#include <iostream>

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