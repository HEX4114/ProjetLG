#ifndef ETAT_H
#define ETAT_H
#include <iostream>
#include <string>

#include "Symbole.h"

class Etat
{
    public:
        Etat();
        virtual ~Etat();
    protected:
        std::string name;
    private:
};

#endif // ETAT_H
