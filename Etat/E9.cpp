#include "E9.h"
#include "Etat.h"
#include "../Automate.h"

#include "E10.h"

E9::E9()
{
	//ctor
}

E9::~E9()
{
	//dtor
}

bool E9::transition(Automate& automate, Symbole *symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(ID) :
			automate.decalageTerminal(symbole, new E10);
			return true;
        case(ERR) :
            return false;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de syntaxe (id manquant).");
	throw(p);
	return false;
}
