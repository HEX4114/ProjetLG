#include <iostream>
#include "Affectation.h"
#include "../../Programme/StatutIdentifiant.h"
#include "../../../Automate.h"

Affectation::Affectation() : Instruction()
{

}

Affectation::Affectation(Variable* v, Expression* e) : Instruction()
{
    partieDroite = e;
    partieGauche = v;
}


Affectation::~Affectation()
{
}


void Affectation::afficher()
{
    std::cout << this->partieGauche->getName() << " := " << this->partieDroite->getName() << ";" << std::endl;
}

void Affectation::executer()
{
    
}

void Affectation::analyseStatique()
{
	StatutIdentifiant* statut;
	if (automate->getStatutIdParIdentifiant(partieGauche->getName()) == NULL)
	{
		std::cerr << "Erreur, variable : " << partieGauche->getName() << " n'est pas declare";
		return;
	}
	else if (!automate->getStatutIdParIdentifiant(partieGauche->getName())->isModifiable())
	{
		std::cerr << "Petit malin, tu as essaye de mondifier une constante : " << partieGauche->getName();
		return;
	}
	statut = automate->getStatutIdParIdentifiant(partieGauche->getName());
	statut->setValeur(partieGauche->getValeur());
	statut->setUtilise(true);
	statut->setModifiable(true);
	automate->majStatutIdentifiant(statut);
}