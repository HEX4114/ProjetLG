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

	//Ajout d'un Statut Identifiant dans le tableau. Renvoie true et ajout l'�l�ment au tableau si son ID n'est pas d�j� pr�sente. Fait
	//le contraire sinon
	bool addStatutIdentifiant(StatutIdentifiant s);

	//Mise � jour du tableau des statuts des variables. Renvoie false si le Id statut identifiant en param�tre n'est pas pr�sent dans la table.
	//Vrai sinon
	bool majStatutIdentifiant(StatutIdentifiant s);

	//Recup�ration d'un pointeur sur Statut identifiant. Renvoie le pointeur si l'identifiant est pr�sent dans le tableau, NULL sinon
	StatutIdentifiant* getStatutIdParIdentifiant(std::string identifiant);


private:
	std::vector<Phrase*> listePhrase;
	std::vector<StatutIdentifiant> tableauStatut;

};

#endif // PROGRAMME_H

