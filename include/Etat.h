#ifndef ETAT_H
#define ETAT_H
#include <iostream>
#include <string>

#include "Symbole.h"


class Automate;

class Etat
{
    public:
        Etat();
        virtual ~Etat();
		virtual void transition(Automate automate, Symbole symbole) = 0;
    protected:
        std::string name;
    private:
};

#endif // ETAT_H
