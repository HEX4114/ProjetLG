#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <stack>

#include "include/Etat.h"

class Automate
{
    public:
        Automate();
        virtual ~Automate();
    protected:
    private:
		std::stack<Etat> pileEtats;
		std::stack<Symbole> pileSymboles;

};

#endif // AUTOMATE_H
