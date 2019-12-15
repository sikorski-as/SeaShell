#ifndef REDIRECTION_EXPR_H
#define REDIRECTION_EXPR_H

#include "Node.h"

class RedirectionExpr : public Node {
    public:
        RedirectionExpr();
        RedirectionExpr(Node* program, Node* input, Node* output);
        ~RedirectionExpr();    
        Node* getProgram();
        void setProgram(Node* program);
        Node* getInput();
        void setInput(Node* input);
        Node* getOutput();
        void setOutput(Node* output);
        NodeType getType();
    private:
        Node* program;
        Node* input;
        Node* output;
};

#endif