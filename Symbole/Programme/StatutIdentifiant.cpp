#include "StatutIdentifiant.h"

#include <iostream>

StatutIdentifiant::StatutIdentifiant()
{
}

StatutIdentifiant::StatutIdentifiant(std::string ID, bool Modifiable, bool Utilise)
{
	id = ID;
	modifiable = Modifiable;
	utilise = Utilise;
	valeurConnue = false;
}


StatutIdentifiant::~StatutIdentifiant()
{
}

void StatutIdentifiant::afficher()
{
	std::cout << id << " : modifiable(" << modifiable << ") valeur(";
	if (valeurConnue)
	{
		std::cout << valeur << ") ";
	}
	else
	{
		std::cout << "valeur non connue) ";
	}
	std::cout << "utilise(" << utilise << ")" << std::endl;
}
