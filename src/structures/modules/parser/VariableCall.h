#include <string>
#include "Assignable.h"

class VariableCall : public Assignable {
    public:
        VariableCall();
        VariableCall(std::string name);
        ~VariableCall();    
        std::string getName();
        void setName(std::string name);
        NodeType getType();
    private:
        std::string name;
};