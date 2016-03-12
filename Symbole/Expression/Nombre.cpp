#include "Nombre.h"

Nombre::Nombre() : Expression()
{
	this->valeur = 0;
}


Nombre::Nombre(double v) : Expression()
{
    this->valeur = v;
}

Nombre::~Nombre()
{
    //dtor
}

double Nombre::evaluer()
{
    return this->valeur;
}

