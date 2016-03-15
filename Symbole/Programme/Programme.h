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

	void addStatutIdentifiant(StatutIdentifiant s){ tableauStatut.push_back(s); };

	//Mise à jour du tableau des statuts des variables. Renvoie false si le Id statut identifiant en paramètre n'est pas présent dans la table.
	//Vrai sinon
	bool majStatutIdentifiant(StatutIdentifiant s);



private:
	std::vector<Phrase*> listePhrase;
	std::vector<StatutIdentifiant> tableauStatut;

};

#endif // PROGRAMME_H

