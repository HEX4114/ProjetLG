#include "Programme.h"
#include "../../Automate.h"
#include <stdlib.h>

Programme::Programme()
{
}


Programme::~Programme()
{
}

void Programme::afficherProgramme()
{
	for (std::list<Phrase*>::iterator it = listePhrase.begin(); it != listePhrase.end(); ++it)
	{
		(*it)->afficher();
	}
}

void Programme::executerProgramme()
{
	for (std::list<Phrase*>::iterator it = listePhrase.begin(); it != listePhrase.end(); ++it)
	{
		(*it)->executer();
	}
}

void Programme::analyseStatique()
{
	for (std::list<Phrase*>::iterator it = listePhrase.begin(); it != listePhrase.end(); ++it)
	{
		(*it)->analyseStatique();
	}
}