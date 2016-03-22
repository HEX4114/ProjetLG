#include <iostream>

#include "DeclarationVariable.h"
#include "StatutIdentifiant.h"


DeclarationVariable::DeclarationVariable() : Declaration()
{
}

DeclarationVariable::~DeclarationVariable()
{
}

void DeclarationVariable::afficher()
{
	std::cout << "VAR " << this->variableADeclarer.getName() << ";" << std::endl;
}

void DeclarationVariable::executer()
{
    StatutIdentifiant * s = new StatutIdentifiant();

    s->setId() = variableADeclarer.identifiant;
    s->setValeur() = variableADeclarer.valeur;

    //tableauStatut.addStatutIdentifiant(StatutIdentifiant s);
}
