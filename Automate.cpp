#include "include/Automate.h"

Automate::Automate()
{
    //ctor
}

Automate::~Automate()
{
    //dtor
}

void Automate::lecture()
{

}

void Automate::empilerEtat(Etat etat)
{
	pileEtats.push(etat);
}

void Automate::empilerSymbole(Symbole symbole)
{
	pileSymboles.push(symbole);
}
