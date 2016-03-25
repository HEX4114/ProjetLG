#ifndef PROGRAMME_H
#define PROGRAMME_H

#include <list>


#include "../Symbole.h"
#include "../Phrase/Phrase.h"
#include "StatutIdentifiant.h"

class Automate;

class Programme :
	public Symbole
{
public:
	Programme();
	virtual ~Programme();

	void afficherProgramme();
	void executerProgramme();
	void analyseStatique();
	
	void setListePhrase(std::list<Phrase*> listePhrase){ this->listePhrase = listePhrase; }
	void setAutomate(Automate* automate){ this->automate = automate; };

private:
	std::list<Phrase*> listePhrase;
	Automate* automate;
};

#endif // PROGRAMME_H

