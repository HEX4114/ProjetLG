#include <iostream>

#include "DeclarationConstante.h"
#include "../../Programme/StatutIdentifiant.h"
#include "../../../Automate.h"

DeclarationConstante::DeclarationConstante() : Declaration()
{
}

DeclarationConstante::~DeclarationConstante()
{
}

void DeclarationConstante::afficher()
{
	std::cout << "const " << this->constanteADeclarer->getName() << " = " << this->constanteADeclarer->getValeur() << ";" << std::endl;
}

void DeclarationConstante::executer()
{
	analyseStatique();
}

void DeclarationConstante::analyseStatique()
{
	StatutIdentifiant * s = new StatutIdentifiant();
	s->setId(constanteADeclarer->getName());
	s->setValeur(constanteADeclarer->getValeur());
	s->setUtilise(false);
	s->setModifiable(false);
	s->setValeurConnue(true);
	automate->addStatutIdentifiant(s);
}
