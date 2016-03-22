#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <stack>
#include <vector>
#include <string>
#include "Etat/Etat.h"

enum Regle {R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, R16, R17, R18, R19};

class Automate
{
    public:
        Automate();
        virtual ~Automate();

		/*Methodes Publiques*/

		void lecture(std::string filename);
		void empilerSymbole(Symbole symbole);
		void empilerEtat(Etat* etat);
		void reduction(Regle regle);
		void decalageTerminal(Symbole symbole, Etat* etat);
		void decalageNonTerminal(Symbole symbole, Etat* etat);
		void accepter();
		bool estUnTerminal(Symbole symbole);
    protected:
    private:
		/*Methodes Privees*/

		/*Attributs Privees*/
		std::stack<Etat*> pileEtats;
		std::stack<Symbole> pileSymboles;
		std::vector<int> reglesReduction;
		std::vector<Symbole> partieGaucheRegle;
		bool lectureFinie;
		//int reglesReduction[19] = { 2, 3, 0, 5, 0, 5, 7, 0, 4, 4, 5, 0, 3, 1, 3, 1, 3, 1, 1 }; // contient le nombre d'états à dépiler pour chaque règle appliquée en réduction.

};

#endif // AUTOMATE_H
