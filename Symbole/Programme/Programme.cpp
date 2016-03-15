#include "Programme.h"


Programme::Programme()
{
}


Programme::~Programme()
{
}

void Programme::afficherProgramme()
{
	for (std::vector<Phrase*>::iterator it = listePhrase.begin(); it != listePhrase.end(); ++it)
	{
		(*it)->afficher();
	}
}

void Programme::afficherTableauStatut()
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		it->afficher();
	}
}

bool Programme::majStatutIdentifiant(StatutIdentifiant s)
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		if (it->getId().compare(s.getId()) == 0)
		{
			(*it) = s;
			return true;
		}
	}
	return false;
}