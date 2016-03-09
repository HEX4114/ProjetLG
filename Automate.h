#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <stack>

#include "Etat/Etat.h"

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
    protected:
    private:
		/*Methodes Privees*/

		/*Attributs Privees*/
		std::stack<Etat*> pileEtats;
		std::stack<Symbole> pileSymboles;

};

#endif // AUTOMATE_H
