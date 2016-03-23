#include <iostream>

#include "DeclarationVariable.h"
#include "../../Programme/StatutIdentifiant.h"
#include "../../../Automate.h"


DeclarationVariable::DeclarationVariable() : Declaration()
{
}

DeclarationVariable::~DeclarationVariable()
{
}

void DeclarationVariable::afficher()
{
	std::cout << "VAR " << this->variableADeclarer->getName() << ";" << std::endl;
}

void DeclarationVariable::executer()
{
	analyseStatique();
}

void DeclarationVariable::analyseStatique()
{
	StatutIdentifiant * s = new StatutIdentifiant();

	s->setId(variableADeclarer->getName());
	s->setValeurConnue(false);
	s->setModifiable(true);

	automate->addStatutIdentifiant(s);
}
