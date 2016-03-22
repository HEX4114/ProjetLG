#ifndef PROGRAMME_H
#define PROGRAMME_H

#include <vector>


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
	


private:
	std::vector<Phrase*> listePhrase;

};

#endif // PROGRAMME_H

