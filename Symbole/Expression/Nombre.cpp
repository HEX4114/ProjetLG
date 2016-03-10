#include "Nombre.h"

Nombre::Nombre() : Expression()
{

}


Nombre::Nombre(double v, std::string id) : Expression()
{
    this->valeur = v;
	this->identifiant = id;
}

Nombre::~Nombre()
{
    //dtor
}

double Nombre::evaluer()
{
    return this->valeur;
}

