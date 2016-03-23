#ifndef PROGRAMME_H
#define PROGRAMME_H

#include <list>


#include "../Symbole.h"
#include "../Phrase/Phrase.h"
#include "StatutIdentifiant.h"



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


private:
	std::list<Phrase*> listePhrase;

};

#endif // PROGRAMME_H

