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
	std::cout << "var " << this->variableADeclarer->getName() << ";" << std::endl;
}

void DeclarationVariable::executer()
{
	analyseStatique();
}

void DeclarationVariable::analyseStatique()
{
	StatutIdentifiant * s = new StatutIdentifiant();

    //if (variableADeclarer->getName()
	s->setId(variableADeclarer->getName());
	s->setValeurConnue(false);
	s->setModifiable(true);
	s->setUtilise(false);

	if (!automate->addStatutIdentifiant(s))
	{
		std::cerr << "la variable " << variableADeclarer->getName() << " est deja declaree" << std::endl;
	}
}
