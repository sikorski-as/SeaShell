#include <vector>
#include "Node.h"

class PipeExpr : public Node {
    public:
        PipeExpr();
        PipeExpr(std::vector<Node> pipes);
        ~PipeExpr();    
        std::vector<Node> getPipes();
        void setPipes(std::vector<Node> pipes);
        NodeType getType();
    private:
        std::vector<Node> pipes;
};