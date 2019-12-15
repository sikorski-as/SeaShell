#include <string>
#include "Node.h"

class Command : public Node {
    public:
        Command();
        Command(std::string commandName);
        ~Command();    
        std::string getCommand();
        void setCommandName(std::string commandName);
        NodeType getType();
    private:
        std::string commandName;
};