#ifndef DECLARATION_H
#define DECLARATION_H

#include "../Phrase.h"
class Declaration :
	public Phrase
{
public:
	Declaration();
	virtual ~Declaration();

	virtual void afficher() = 0;
	virtual void executer() = 0;
};

#endif // DECLARATION_H

