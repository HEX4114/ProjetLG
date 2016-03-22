#include <sstream>
#include "Constante.h"

Constante::Constante() : Expression()
{
}

Constante::Constante(double v, std::string id) : Expression()
{
	valeur = v;
	identifiant = id;
}

Constante::~Constante()
{
}


double Constante::evaluer()
{
	return this->valeur;
}
