#ifndef PHRASE_H
#define PHRASE_H


#include "../Symbole.h"

class Phrase :
	public Symbole
{
public:
	Phrase();

	virtual void afficher() = 0;
	virtual void executer() = 0;

	virtual ~Phrase();
};

#endif // PHRASE_H

