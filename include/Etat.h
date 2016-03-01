#ifndef ETAT_H
#define ETAT_H
#include <iostream>
#include <string>
#include "Automate.h"
#include "Symbole.h"
using namespace std;

class Etat
{
    public:
        Etat();
        virtual ~Etat();
    protected:
        string name;
    private:
};

#endif // ETAT_H
