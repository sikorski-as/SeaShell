#include "Identifier.h"

Identifier::Identifier() {
    this->type = NodeType::IDENTIFIER;
}
Identifier::Identifier(std::string identifier) {
    this->identifier = identifier;
    this->type = NodeType::IDENTIFIER;
}
Identifier::~Identifier(){}   
std::string Identifier::getIdentifier(){
    return this->identifier;
}
void Identifier::setIdentifier(std::string identifier){
    this->identifier = identifier;
}
NodeType Identifier::getType() {
    return this->type;
}
