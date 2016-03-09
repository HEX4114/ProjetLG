#include "Automate.h"


Automate::Automate()
{
    //ctor
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

}

void Automate::decalage(Symbole symbole, Etat* etat)
{

}
