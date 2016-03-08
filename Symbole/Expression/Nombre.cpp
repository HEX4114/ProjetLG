#include "Nombre.h"

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

