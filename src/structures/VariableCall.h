#ifndef VARIABLE_CALL_H
#define VARIABLE_CALL_H

#include <string>
#include "Assignable.h"

class VariableCall : public Assignable {
    public:
        VariableCall();
        VariableCall(std::string name);
        ~VariableCall();    
        std::string getName();
        void setName(std::string name);
        NodeType getType() override;
        std::string toString() override;
    private:
        std::string name;
};

#endif