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
    std::cout << this->expressionAAfficher->evaluer() << std::endl;
}

void Ecrire::analyseStatique()
{
	if (!expressionAAfficher->expressionConnue())
	{
		std::cerr << "Expression non connue : " << expressionAAfficher->getName() << std::endl;
		return;
	}
	else if (!expressionAAfficher->expressionDeclare())
	{
		std::cerr << "Expression non declare : " << expressionAAfficher->getName() << std::endl;;
		return;
	}
}
