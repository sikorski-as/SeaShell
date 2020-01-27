#include "Context.h"
#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <vector>

void Context::setVariable(std::string key, std::string value) {
    this->localVars[key] = value;
}

void Context::exportVariable(std::string key, std::string value) {
    this->setVariable(key, value);
    setenv(key.c_str(), value.c_str(), true);
}

std::string Context::getVariable(std::string key) {
    if (key == "?") {
        return std::to_string(lastReturnCode);
    }
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
    std::vector<std::string> cont;
    split(s, cont, "'");
    bool afterSingleQuote = false;
    std::vector<std::string> results;
    int i = 0;
    for (auto m: cont) {
        if (i % 2 == 1)
            afterSingleQuote = true;
        else
            afterSingleQuote = false;
        i++;
        auto indx = m.find('$', 0);
        while (indx != std::string::npos && !afterSingleQuote) {
            if (indx == 0 || m.at(indx - 1) != '\\') { // this is not escaped
                bool search = true;
                bool hasName = true;
                int pos = -1;
                if (indx + 1 < m.length() && m.at(indx + 1) == '?') { //return code
                    std::string resolvedVariable = this->getVariable("?");
                    m.replace(indx, indx + 2, resolvedVariable);
                    if (indx + resolvedVariable.length() < m.length())
                        indx = m.find('$', indx + resolvedVariable.length());
                    else
                        indx = std::string::npos;
                } else {
                    for (int i = indx + 1; i < m.length() && search; i++) {
                        char c = m.at(i);
                        if (!isalnum(c) && c != '_') {
                            if (i == indx + 1)
                                hasName = false;
                            search = false;
                            pos = i;
                        }
                    }
                    if (pos == -1)
                        pos = m.length();
                    if (hasName && indx + 1 < m.length()) { // do a replacement if there is name after $
                        std::string variableName = m.substr(indx + 1, pos - indx - 1);
                        std::string resolvedVariable = this->getVariable(variableName);
                        //                std::cerr << "Resolving " << variableName << " : " << resolvedVariable << "\n";
                        m.replace(indx, pos - indx, resolvedVariable);
                        if (indx + resolvedVariable.length() < m.length())
                            indx = m.find('$', indx + resolvedVariable.length());
                        else
                            indx = std::string::npos;
                    } else
                        indx = m.find('$', indx + 1);
                }
            } else {
                if (m.at(indx - 1) == '\\') { // delete replacement
                    m.replace(indx - 1, 1, "");
                }
                indx = m.find('$', indx + 1);
            }
        }
        results.push_back(m);
    }
    std::string result = "";
    for (auto m : results) {
        result += m;
    }
    return result;
}

void Context::setWorkingDirectory(std::string newWorkingDirectory) {
    int result = chdir(newWorkingDirectory.c_str());
    if (result == -1) {
        std::cerr << strerror(errno) << std::endl;
    }
}

std::string Context::getWorkingDirectory() {
    char *workingDirectoryBuffer = get_current_dir_name();
    std::string workingDirectory = workingDirectoryBuffer;
    if (workingDirectory.back() != '/') {
        workingDirectory += '/';
    }
    free(workingDirectoryBuffer);
    return workingDirectory;
}

bool Context::isRunning() {
    return this->running;
}

void Context::stop() {
    this->running = false;
}

void Context::setLastReturnCode(int code) {
    lastReturnCode = code;
}

int Context::getLastReturnCode() {
    return lastReturnCode;
}

void Context::split(const std::string &str, std::vector<std::string> &cont,
                    const std::string &delims) {
    std::size_t current, previous = 0;
    current = str.find_first_of(delims);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find_first_of(delims, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}