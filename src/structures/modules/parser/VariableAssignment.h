#ifndef VARIABLE_ASSIGNMENT_H
#define VARIABLE_ASSIGNMENT_H

#include <string>
#include "Assignable.h"

class VariableAssignment : public Node {
    public:
        VariableAssignment();
        VariableAssignment(std::string name, Assignable assigned);
        ~VariableAssignment();    
        std::string getName();
        void setName(std::string name);
        Assignable getArguments();
        void setArguments(Assignable assigned);
        NodeType getType();
    private:
        std::string name;
        Assignable assigned;
};

#endif