#ifndef SYMBOLE_H
#define SYMBOLE_H

#include <string.h>

enum TypeSymbole {ID, NB, VAR, CONST, ECRIRE, LIRE, AF, VG, EG, PVG, OPA, OPM, PARG, PARD, DOL, P, D, I, V, C, E, T, F};

class Symbole
{
    public:
		Symbole() {}
        virtual ~Symbole();
		int getId() { return Id; }
    protected:
		int Id;
    private:
};

#endif // SYMBOLE_H
