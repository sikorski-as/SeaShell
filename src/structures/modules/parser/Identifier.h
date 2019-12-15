#include <string>
#include "Assignable.h"

class Identifier : public Assignable {
    public:
        Identifier();
        Identifier(std::string identifier);
        ~Identifier();    
        std::string getIdentifier();
        void setIdentifier(std::string identifier);
        NodeType getType();
    private:
        std::string identifier;
};