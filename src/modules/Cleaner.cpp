#include "Cleaner.h"

void Cleaner::clean(Program* program){
    if(program != nullptr) {
        for(Node* nodePtr: program->getCommands()) {
            if(nodePtr != nullptr) {
                NodeType type = nodePtr->getType();
                if(type == NodeType::PROGRAM) {
                    Program *inside = dynamic_cast<Program*>(nodePtr);
                    if(program!= inside)
                        clean(inside);
                } else
                     cleanNode(nodePtr); 
            }
        }
    }
}

void Cleaner::cleanIdentifier(Identifier *identifier){}
void Cleaner::cleanBackTickExpr(BackTickExpr* backTickExpr) {
    if(backTickExpr != nullptr) {
        Program p = backTickExpr->getProgram();
        this->clean(&p);
        delete &p;
    }
}
void Cleaner::cleanCommand(Command* command){
    if(command != nullptr) {
        Node* commandName = command->getCommandName(); //backTick expr / identifier
        std::vector<Node*> arguments = command->getArguments();
        cleanNode(commandName);
        for(Node* nodePtr: arguments) {
            cleanNode(nodePtr);
        }
    }
}
void Cleaner::cleanPipeExpr(PipeExpr* pipeExpr){
    if(pipeExpr != nullptr) {
        for(Node* nodePtr: pipeExpr->getPipes()) {
            cleanNode(nodePtr);
        }
    }
}
void Cleaner::cleanRedirectionExpr(RedirectionExpr* redirectionExpr){
    if(redirectionExpr != nullptr) {
        cleanNode(redirectionExpr->getInput());
        cleanNode(redirectionExpr->getOutput());
        cleanNode(redirectionExpr->getProgram());
    }
}
void Cleaner::cleanVariableAssignment(VariableAssignment* variableAssignment){
    if(variableAssignment != nullptr) {
        cleanNode(variableAssignment->getValue());
    }
}
void Cleaner::cleanVariableCall(VariableCall* variableCall){}


void Cleaner::cleanNode(Node* nodePtr) {
    if(nodePtr != nullptr) {
        NodeType type = nodePtr->getType();
        switch (type)
        {
        case NodeType::PROGRAM: {
            Program *inside = dynamic_cast<Program*>(nodePtr);
            clean(inside);
            delete dynamic_cast<Program*>(nodePtr);
            break;
        }
        case NodeType::BACKTICK_EXPR: {
            this->cleanBackTickExpr(dynamic_cast<BackTickExpr*>(nodePtr));
            delete dynamic_cast<BackTickExpr*>(nodePtr);
            break;
        }
        case NodeType::IDENTIFIER: {
            this->cleanIdentifier(dynamic_cast<Identifier*>(nodePtr));
            delete dynamic_cast<Identifier*>(nodePtr);
            break;
        }
        case NodeType::COMMAND: {
            this->cleanCommand(dynamic_cast<Command*>(nodePtr));
            delete dynamic_cast<Command*>(nodePtr);
            break;
        }
        case NodeType::PIPE_EXPR: {
            this->cleanPipeExpr(dynamic_cast<PipeExpr*>(nodePtr));
            delete dynamic_cast<PipeExpr*>(nodePtr);
            break;
        }
        case NodeType::REDIRECTION_EXPR: {
            this->cleanRedirectionExpr(dynamic_cast<RedirectionExpr*>(nodePtr));
            delete dynamic_cast<RedirectionExpr*>(nodePtr);
            break;
        }
        case NodeType::VARIABLE_ASSIGNMENT: {
            this->cleanVariableAssignment(dynamic_cast<VariableAssignment*>(nodePtr));
            delete dynamic_cast<VariableAssignment*>(nodePtr);
            break;
        }
        case NodeType::VARIABLE_CALL: {
            this->cleanVariableCall(dynamic_cast<VariableCall*>(nodePtr));
            delete dynamic_cast<VariableCall*>(nodePtr);
            break;
        }                               
        default:
            break;
        }
    }
}