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