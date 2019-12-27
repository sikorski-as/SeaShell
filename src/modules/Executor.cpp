
#include <iostream>
#include "Executor.h"
#include "Context.h"
#include "../structures/VariableAssignment.h"
#include "../structures/Identifier.h"

bool Executor::isRunning() {
    return this->running;
}

void Executor::execute(Program &program) {
    std::cout << "Executing!\n";

    for (auto cmd: program.getCommands()) {
        try {
            // TODO wrap in try-catch
            // TODO exit
            auto type = cmd->getType();
            // TODO pobieraj stringi aby potem wyswietlac je na konsoli (aby dzialal backtick)
            switch (type) {
                case NodeType::VARIABLE_ASSIGNMENT:
                    std::cout << executeVariableAssignment(dynamic_cast<VariableAssignment*>(cmd)) << std::endl;
                    break;
                case NodeType::COMMAND:
                    std::cout << executeCommand(dynamic_cast<Command*>(cmd)) << std::endl;
                    break;
                case NodeType::REDIRECTION_EXPR:
                    std::cout << executeRedirectionExpression(dynamic_cast<RedirectionExpr*>(cmd))<< std::endl;
                    break;
                case NodeType::PIPE_EXPR:
                    std::cout << executePipeExpression(dynamic_cast<PipeExpr*>(cmd)) << std::endl;
                    break;
                case NodeType::BACKTICK_EXPR:
                    std::cout << executeBackTickExpression(dynamic_cast<BackTickExpr*>(cmd))<< std::endl;
                    break;
                default:
                    throw std::runtime_error("Unexpected input");
            }
        } catch (std::runtime_error error) {
            std::cout << error.what() << std::endl;
        }
    }

    this->running = false;
}

std::string Executor::executeProgram(Program &program) { // TODO test
    std::string output = "";
    for (auto cmd: program.getCommands()) {
        try {
            auto type = cmd->getType();
            switch (type) {
                case NodeType::VARIABLE_ASSIGNMENT:
                    output += executeVariableAssignment(dynamic_cast<VariableAssignment*>(cmd));
                    break;
                case NodeType::COMMAND:
                    output += executeCommand(dynamic_cast<Command*>(cmd));
                    break;
                case NodeType::REDIRECTION_EXPR:
                    output += executeRedirectionExpression(dynamic_cast<RedirectionExpr*>(cmd));
                    break;
                case NodeType::PIPE_EXPR:
                    output += executePipeExpression(dynamic_cast<PipeExpr*>(cmd));
                    break;
                case NodeType::BACKTICK_EXPR: {
                    std::string command = executeBackTickExpression(dynamic_cast<BackTickExpr*>(cmd));
                    // TODO sprobuj wykonac to jako komendę - wbudowaną lub nie?
                    break;
                }
                default:
                    throw std::runtime_error("Unexpected input");
        }
        } catch (std::runtime_error error) {
            output += error.what();
        }
    }

    return output;
}


std::string Executor::executeVariableAssignment(VariableAssignment *varAssignment) {
    auto assignable = varAssignment->getValue();
    auto type = assignable->getType();
    if(type == NodeType::BACKTICK_EXPR){
        throw std::runtime_error("TODO");
        std::string value = executeBackTickExpression(dynamic_cast<BackTickExpr*>(assignable));
        this->context.setVariable(varAssignment->getName(), value);
        // std::cout << "[executeVariableAssignment] BACKTICK : " << this->context.getVariable(varAssignment->getName()) << std::endl;
    }
    else if(type == NodeType::IDENTIFIER){
        auto value = dynamic_cast<Identifier*>(assignable);
        // TODO value powinno być sprawdzane pod kątem replacowania zmiennych
        this->context.setVariable(varAssignment->getName(), value->getIdentifier());
        // std::cout << "[executeVariableAssignment] IDENT : " << this->context.getVariable(varAssignment->getName()) << std::endl;
    } else if(type == NodeType::VARIABLE_CALL) {
        auto variableCall = dynamic_cast<VariableCall*>(assignable);
        std::string variableContent = this->context.getVariable(variableCall->getName());
        this->context.setVariable(varAssignment->getName(), variableContent);
        // std::cout << "[executeVariableAssignment] VAR_CALL : " << this->context.getVariable(varAssignment->getName()) << std::endl;
    } else 
        throw std::runtime_error("Unexpected type in the variable assignment");
    
    return EMPTY_STRING;
}

std::string Executor::executeCommand(Command *command) {
    Node* commandName = command->getCommandName(); //backTick expr / identifier
    std::vector<Node*> arguments = command->getArguments(); // TODO przekazujac argumenty jesli IDENTIFIER powinno być sprawdzane pod kątem replacowania zmiennych
    NodeType commandNameType = commandName->getType();
    if(commandNameType == NodeType::IDENTIFIER) {
        // TODO sprawdz czy wbudowane czy niewbudowane
        throw std::runtime_error("TODO");
    } else if(commandNameType == NodeType::BACKTICK_EXPR) {
        throw std::runtime_error("TODO");
    } else {
        throw std::runtime_error("Unexpected type in the command");
    }

    return ""; // TODO
}

std::string Executor::executeRedirectionExpression(RedirectionExpr* redirectionExpr) {
    Node* command = redirectionExpr->getCommand(); // identifier / backtickexpr / command? TODO
    Node* input = redirectionExpr->getInput();
    Node* output = redirectionExpr->getOutput();

    NodeType type = command->getType();
    if(type == NodeType::BACKTICK_EXPR){
        throw std::runtime_error("TODO");
    } else if(type == NodeType::IDENTIFIER) {
        throw std::runtime_error("TODO");
    } else if(type == NodeType::COMMAND) {
        throw std::runtime_error("TODO");
    } else {
         throw std::runtime_error("Unexpected type in the redirection expression");
    }

    return ""; // TODO
}

std::string Executor::executePipeExpression(PipeExpr* pipeExpr) {
    std::vector<Node*> pipes = pipeExpr->getPipes();
    throw std::runtime_error("TODO");
}

std::string Executor::executeBackTickExpression(BackTickExpr* backTickExpr) {
    Program* p = backTickExpr->getProgram();
    Context old = this->context; // TODO copy old context

    throw std::runtime_error("TODO TEST");
    std::string backTickString =  this->executeProgram(*p); // TODO w takim razie wywolanie execute powinno byc rozbite na execute i executeProgram i context powinien byc nowy tworzony

    this->context = old; // TODO restore context

    return backTickString;

    // lolek = 1234; echo `lolek=5678; echo $lolek` $lolek
    // wypisuje: 5678 1234
}



