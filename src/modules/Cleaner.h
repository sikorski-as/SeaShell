#ifndef CLEANER_H
#define CLEANER_H

#include "../../tests/TestInclude.h"

class Cleaner {
    public:
        void clean(Program *program);
        Cleaner(){};
    private:
        void cleanIdentifier(Identifier* identifier);
        void cleanBackTickExpr(BackTickExpr* backTickExpr);
        void cleanCommand(Command* command);
        void cleanPipeExpr(PipeExpr* pipeExpr);
        void cleanRedirectionExpr(RedirectionExpr* redirectionExpr);
        void cleanVariableAssignment(VariableAssignment* variableAssignment);
        void cleanVariableCall(VariableCall* variableCall);
        void cleanNode(Node* nodePtr);
};


#endif