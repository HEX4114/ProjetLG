#include "Programme.h"
#include <stdlib.h>

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

void Programme::executerProgramme()
{
	for (std::vector<Phrase*>::iterator it = listePhrase.begin(); it != listePhrase.end(); ++it)
	{
		(*it)->executer();
	}
}

void Programme::afficherTableauStatut()
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		it->afficher();
	}
}

bool Programme::addStatutIdentifiant(StatutIdentifiant s)
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		if (it->getId().compare(s.getId()) == 0)
		{
			return false;
		}
	}
	tableauStatut.push_back(s);
	return true;
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

StatutIdentifiant* Programme::getStatutIdParIdentifiant(std::string identifiant)
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		if (it->getId().compare(identifiant) == 0)
		{
			return &(*it);
		}
	}

	return NULL;
}