#include <vector>
#include "Node.h"

class Program: public Node {
    public:
        Program();
        Program(std::vector<Node> commands);
        ~Program();    
        std::vector<Node> getCommands();
        void setCommands(std::vector<Node> commands);
        NodeType getType();
    private:
        std::vector<Node> commands;
};