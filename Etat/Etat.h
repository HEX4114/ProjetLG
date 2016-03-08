#ifndef ETAT_H
#define ETAT_H
#include <iostream>
#include <string>

#include "Symbole/Symbole.h"


class Automate;

class Etat
{
    public:
        Etat();
        virtual ~Etat();
		virtual bool transition(Automate automate, Symbole symbole) = 0;
    protected:
        std::string name;
    private:
};

#endif // ETAT_H
