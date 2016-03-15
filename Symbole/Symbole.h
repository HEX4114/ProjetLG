#ifndef SYMBOLE_H
#define SYMBOLE_H

#include <string.h>

enum TypeSymbole {ID, NB, VAR, CONST, ECRIRE, LIRE, AF, VG, EG, PVG, OPA, OPM, PLUS, MOINS, MULT, DIV,PARG, PARD, DOL, P, D, I, V, C, E, T, F};

class Symbole
{
    public:
		Symbole() {}
		Symbole(enum TypeSymbole t) { type = t; }
        virtual ~Symbole();
		int getId() { return Id; }

		enum TypeSymbole getType(){ return type; };
		void setType(enum TypeSymbole t){ type = t; };

    protected:
		int Id;
		enum TypeSymbole type;
    private:
};

#endif // SYMBOLE_H
