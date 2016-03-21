#include "Automate.h"


Automate::Automate()
{
    //ctor
	reglesReduction.push_back(2);
	reglesReduction.push_back(3);
	reglesReduction.push_back(0);
	reglesReduction.push_back(5);
	reglesReduction.push_back(0);
	reglesReduction.push_back(5);
	reglesReduction.push_back(7);
	reglesReduction.push_back(0);
	reglesReduction.push_back(4);
	reglesReduction.push_back(4);
	reglesReduction.push_back(5);
	reglesReduction.push_back(0);
	reglesReduction.push_back(3);
	reglesReduction.push_back(1);
	reglesReduction.push_back(3);
	reglesReduction.push_back(1);
	reglesReduction.push_back(3);
	reglesReduction.push_back(1);
	reglesReduction.push_back(1);
}

Automate::~Automate()
{
	// TODO
	/*
	for (int i = 0; i < pileEtats.size; i++)
	{
		delete(pileEtats.pop);
	}
	*/
}

void Automate::lecture()
{

}

void Automate::empilerEtat(Etat* etat)
{
	pileEtats.push(etat);
}

void Automate::empilerSymbole(Symbole symbole)
{
	pileSymboles.push(symbole);
}

void Automate::reduction(Regle regle, Symbole symbole)
{
	int nbPop = reglesReduction.at(regle);

	for (int i=0; i<nbPop; i++) pileEtats.pop();
	
	pileEtats.top()->transition(*this, symbole);
}

void Automate::decalage(Symbole symbole, Etat* etat)
{
	empilerSymbole(symbole);
	empilerEtat(etat);
}

void Automate::afficherTableauStatut()
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		it->afficher();
	}
}

bool Automate::addStatutIdentifiant(StatutIdentifiant s)
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		if (it->getId().compare(s.getId()) == 0)
		{
			return false;
		}
	}
	tableauStatut.push_back(s);
	return true;
}

bool Automate::majStatutIdentifiant(StatutIdentifiant s)
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		if (it->getId().compare(s.getId()) == 0)
		{
			(*it) = s;
			return true;
		}
	}
	return false;
}

StatutIdentifiant* Automate::getStatutIdParIdentifiant(std::string identifiant)
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		if (it->getId().compare(identifiant) == 0)
		{
			return &(*it);
		}
	}

	return NULL;
}