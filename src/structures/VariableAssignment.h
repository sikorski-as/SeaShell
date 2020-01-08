#ifndef VARIABLE_ASSIGNMENT_H
#define VARIABLE_ASSIGNMENT_H

#include <string>
#include "Assignable.h"
#include "Node.h"

class VariableAssignment : public Node {
    public:
        VariableAssignment();
        VariableAssignment(std::string name, Assignable* assigned);
        ~VariableAssignment();    
        std::string getName();
        void setName(std::string name);
        Assignable* getValue();
        void setValue(Assignable* assigned);
        NodeType getType() override;
        std::string toString() override;
    private:
        std::string name;
        Assignable* assigned;
};

#endif