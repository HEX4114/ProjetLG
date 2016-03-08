#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <stack>

#include "Etat.h"
#include "Symbole.h"

class Automate
{
    public:
        Automate();
        virtual ~Automate();

		/*Methodes Publiques*/

		void lecture();
		void empilerSymbole(Symbole symbole);
		void empilerEtat(Etat etat);

    protected:
    private:
		/*Methodes Privees*/

		/*Attributs Privees*/
		std::stack<Etat> pileEtats;
		std::stack<Symbole> pileSymboles;

};

#endif // AUTOMATE_H
