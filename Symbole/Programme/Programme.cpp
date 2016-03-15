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
