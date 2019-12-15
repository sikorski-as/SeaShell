#include "Context.h"
#include <stdlib.h>
#include <iostream>

void Context::setVariable(std::string key, std::string value){
    this->localVars[key] = value;
}

void Context::exportVariable(std::string key, std::string value){
    // this->setVariable(key, value);
    std::string exportString = key + "=" + value;
    const char* exportChars = exportString.c_str();
    int ret = putenv( (char*)exportChars );
    std::cout<<ret<<std::endl;
}

std::string Context::getVariable(std::string key){
    std::map<std::string, std::string>::iterator it = this->localVars.find(key);
    if(it != localVars.end()) {
        //element found
        std::cout<<"Getting from local";
        return it->second;
    }
    char* envVal = getenv( (char*)key.c_str() );
    if(envVal != NULL) {
        std::cout<<"Getting from env";
        return std::string(envVal);
    }

    return "No";
}