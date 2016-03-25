#include <iostream>
#include "Ecrire.h"

Ecrire::Ecrire() : Instruction()
{
}


Ecrire::~Ecrire()
{
}


void Ecrire::afficher()
{
    std::cout << "ecrire " << this->expressionAAfficher->getName() << ";" << std::endl;
}

void Ecrire::executer()
{
	analyseStatique();
    std::cout << this->expressionAAfficher->evaluer() << std::endl;
}

void Ecrire::analyseStatique()
{
	if (!expressionAAfficher->expressionConnue())
	{
		std::cerr << "une valeur dans l'expression " << expressionAAfficher->getName() << " n'est pas connue." << std::endl;
		return;
	}
	else if (!expressionAAfficher->expressionDeclare())
	{
		std::cerr << "une valeur dans l'expression " << expressionAAfficher->getName() << " n'est pas declaree"<< std::endl;
		return;
	}
	expressionAAfficher->setUtilise();
}
