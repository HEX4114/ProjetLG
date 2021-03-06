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
	analyseStatique();
}

void Affectation::analyseStatique()
{
	StatutIdentifiant* statut = automate->getStatutIdParIdentifiant(partieGauche->getName());
	partieDroite->setUtilise();
	if (statut == NULL)
	{
		std::cerr << "la variable " << partieGauche->getName() << " n'a pas ete declaree" << std::endl;
		return;
	}
	else if (!statut->isModifiable())
	{
		std::cerr << "Impossible de modifier une constante " << partieGauche->getName() << std::endl;
		return;
	}
	else if (!partieDroite->expressionConnue())
	{
		std::cerr << "une valeur dans l'expression " << partieDroite->getName() << " n'est pas connue." << std::endl;
		return;
	}
	else if (!partieDroite->expressionDeclare())
	{
		std::cerr << "une valeur dans l'expression " << partieDroite->getName() << " n'est pas declaree." << std::endl;
		return;
	}

	statut->setValeur(partieDroite->evaluer());
	statut->setValeurConnue(true);
	statut->setModifiable(true);
	automate->majStatutIdentifiant(statut);
}