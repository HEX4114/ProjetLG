#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <stack>
#include <vector>
#include <string>
#include <list>
#include "Etat/Etat.h"
#include "Lexer.h"
#include "Symbole/Programme/StatutIdentifiant.h"
#include "Symbole/Programme/Programme.h"

class ExpressionBinaire;

enum Regle {R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, R16, R17, R18, R19};

class Automate
{
    public:
        Automate();
        virtual ~Automate();

		/*Methodes Publiques*/

		void lecture(std::string filename);
		void empilerSymbole(Symbole* symbole);
		void empilerEtat(Etat* etat);

		void reduction(Regle regle);
		void decalageTerminal(Symbole* symbole, Etat* etat);
		void decalageNonTerminal(Symbole* symbole, Etat* etat);
		void decalageAnticipe(Symbole* symbole, Etat* etat);
		
		void accepter();


		void afficherTableauStatut();

		//Ajout d'un Statut Identifiant dans le tableau. Renvoie true et ajout l'élément au tableau si son ID n'est pas déjà présente. Fait
		//le contraire sinon
		bool addStatutIdentifiant(StatutIdentifiant* s);

		//Mise à jour du tableau des statuts des variables. Renvoie false si l'Id du statut identifiant en paramètre n'est pas présent dans la table.
		//Vrai sinon
		bool majStatutIdentifiant(StatutIdentifiant* s);

		//Recupération d'un pointeur sur Statut identifiant. Renvoie le pointeur si l'identifiant est présent dans le tableau, NULL sinon
		StatutIdentifiant* getStatutIdParIdentifiant(std::string identifiant);

		Programme concatenerSymboles();


    protected:
    private:
		/*Methodes Privees*/

		/*Attributs Privees*/
		std::stack<Etat*> pileEtats;
		std::stack<Symbole*> pileSymboles;
		std::vector<int> reglesReduction;
		std::vector<Symbole*> partieGaucheRegle;
		bool lectureFinie;
		Lexer* lex;
		//int reglesReduction[19] = { 2, 3, 0, 5, 0, 5, 7, 0, 4, 4, 5, 0, 3, 1, 3, 1, 3, 1, 1 }; // contient le nombre d'états à dépiler pour chaque règle appliquée en réduction.
		std::vector<StatutIdentifiant*> tableauStatut;

		std::list<Symbole*> viderPileSymbole();
		void remplirPileSymbole(std::list<Symbole*> liste);

		std::string getIDValue(Symbole* symbole);
		double getNumberValue(Symbole* symbole);
		Programme creerObjetsPhrase(std::list<std::list<Symbole*>> listeSymbole);
		Expression* parseExpression(std::list<Symbole*>::iterator it);
		bool estPrioritaire(TypeSymbole t1, TypeSymbole t2);
		ExpressionBinaire* creerExpressionBinaire(TypeSymbole t1, Expression* e1, Expression* e2);
};

#endif // AUTOMATE_H
