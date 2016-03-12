#include "Constante.h"


Constante::Constante() : Expression()
{
}

Constante::Constante(double v, std::string id) : Expression()
{
	valeur = v;
	identifiant = id;
}

double Constante::evaluer()
{
	return this->valeur;
}


Constante::~Constante()
{
}
