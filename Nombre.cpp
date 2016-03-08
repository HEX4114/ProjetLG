#include "include/Nombre.h"

Nombre::Nombre() : Expression()
{
    //ctor
}

Nombre::~Nombre()
{
    //dtor
}

double Nombre::evaluer()
{
    return this->valeur;
}

