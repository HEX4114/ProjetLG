#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <stack>
#include <vector>

#include "Etat/Etat.h"
#include "Symbole/Programme/StatutIdentifiant.h"

enum Regle {R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, R16, R17, R18, R19};

class Automate
{
    public:
        Automate();
        virtual ~Automate();

		/*Methodes Publiques*/

		void lecture();
		void empilerSymbole(Symbole symbole);
		void empilerEtat(Etat* etat);
		void reduction(Regle regle, Symbole symbole);
		void decalage(Symbole symbole, Etat* etat);

		void afficherTableauStatut();

		//Ajout d'un Statut Identifiant dans le tableau. Renvoie true et ajout l'�l�ment au tableau si son ID n'est pas d�j� pr�sente. Fait
		//le contraire sinon
		bool addStatutIdentifiant(StatutIdentifiant s);

		//Mise � jour du tableau des statuts des variables. Renvoie false si l'Id du statut identifiant en param�tre n'est pas pr�sent dans la table.
		//Vrai sinon
		bool majStatutIdentifiant(StatutIdentifiant s);

		//Recup�ration d'un pointeur sur Statut identifiant. Renvoie le pointeur si l'identifiant est pr�sent dans le tableau, NULL sinon
		StatutIdentifiant* getStatutIdParIdentifiant(std::string identifiant);

    protected:
    private:
		/*Methodes Privees*/

		/*Attributs Privees*/
		std::stack<Etat*> pileEtats;
		std::stack<Symbole> pileSymboles;
		std::vector<int> reglesReduction;
		//int reglesReduction[19] = { 2, 3, 0, 5, 0, 5, 7, 0, 4, 4, 5, 0, 3, 1, 3, 1, 3, 1, 1 }; // contient le nombre d'�tats � d�piler pour chaque r�gle appliqu�e en r�duction.
		std::vector<StatutIdentifiant> tableauStatut;
};

#endif // AUTOMATE_H
