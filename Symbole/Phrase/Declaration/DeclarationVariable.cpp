#include <iostream>

#include "DeclarationVariable.h"


DeclarationVariable::DeclarationVariable() : Declaration()
{
}


DeclarationVariable::~DeclarationVariable()
{
}

void DeclarationVariable::afficher()
{
	std::cout << "VAR " << this->variableADeclarer.getIdentifiant() << ";" << std::endl;
}

void DeclarationVariable::executer()
{

}