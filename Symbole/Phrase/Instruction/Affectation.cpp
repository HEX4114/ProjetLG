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
    double valeurAAffectee = partieDroite->evaluer();
    partieGauche->setValeur(valeurAAffectee);

	//MAJ statut identifiant
	StatutIdentifiant statut;
	statut = (*automate->getStatutIdParIdentifiant(partieGauche->getName()));
	statut.setValeur(partieGauche->getValeur());
	statut.setUtilise(true);
	statut.setModifiable(true);
	automate->majStatutIdentifiant(statut);
}
