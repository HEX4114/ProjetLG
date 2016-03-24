#include<iostream>
#include "Lire.h"
#include "../../Programme/StatutIdentifiant.h"
#include "../../../Automate.h"


Lire::Lire() : Instruction()
{
}

Lire::Lire(Variable* v) : Instruction()
{
    variableAChanger = v;
}

Lire::~Lire()
{
}

void Lire::afficher()
{
    std::cout << "lire " << this->variableAChanger->getName() << ";" << std::endl;
}

void Lire::executer()
{
	analyseStatique();
	double n;
	std::cin >> n;
	StatutIdentifiant* statut;
	statut = automate->getStatutIdParIdentifiant(variableAChanger->getName());
	statut->setValeur(n);
	automate->majStatutIdentifiant(statut);
}

void Lire::analyseStatique()
{
	StatutIdentifiant* statut;
	statut = automate->getStatutIdParIdentifiant(variableAChanger->getName());

	if (statut == NULL)
	{
		std::cerr << "la variable " << variableAChanger->getName() << " n'a pas ete declaree" << std::endl;
		return;
	}
	else if (!statut->isModifiable())
	{
		std::cerr << "Erreur : impossible de modifier la constante " << variableAChanger->getName() << std::endl;
		return;
	}
	statut->setValeurConnue(true);

}
