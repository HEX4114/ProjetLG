#ifndef PHRASE_H
#define PHRASE_H


#include "../Symbole.h"

class Automate;

class Phrase :
	public Symbole
{
public:
	Phrase();

	virtual void afficher() = 0;
	virtual void analyseStatique() = 0;
	virtual void executer() = 0;

	virtual ~Phrase();

	void setAutomate(Automate* automate){ this->automate = automate; };

protected:
	Automate* automate;

};

#endif // PHRASE_H

