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
	void afficherTableauStatut();

private:
	std::vector<Phrase> listePhrase;
	std::vector<StatutIdentifiant> tableauStatut;

};

#endif // PROGRAMME_H

