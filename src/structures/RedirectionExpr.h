#ifndef REDIRECTION_EXPR_H
#define REDIRECTION_EXPR_H

#include "Node.h"

class RedirectionExpr : public Node {
    public:
        RedirectionExpr();
        RedirectionExpr(Node* command, Node* input, Node* output);
        ~RedirectionExpr();    
        Node* getCommand();
        void setCommand(Node* command);
        Node* getInput();
        void setInput(Node* input);
        Node* getOutput();
        void setOutput(Node* output);
        NodeType getType();
    private:
        Node* command;
        Node* input;
        Node* output;
};

#endif