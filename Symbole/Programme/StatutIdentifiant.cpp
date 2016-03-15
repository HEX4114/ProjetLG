#include "StatutIdentifiant.h"

#include <iostream>

StatutIdentifiant::StatutIdentifiant()
{
}

StatutIdentifiant::StatutIdentifiant(std::string ID, bool Modifiable, bool Utilise, bool ValeurConnue)
{
	id = ID;
	modifiable = Modifiable;
	utilise = Utilise;
	valeurConnue = ValeurConnue;
}


StatutIdentifiant::~StatutIdentifiant()
{
}

void StatutIdentifiant::afficher()
{
	std::cout << id << " : modifiable ("<<modifiable << ") valeur (" << valeur << ")" << std::endl;
}
