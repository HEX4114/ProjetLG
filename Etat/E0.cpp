#include "E0.h"
#include "Etat.h"
#include "../Automate.h"

#include "E1.h"

E0::E0()
{
	//ctor
}

E0::~E0()
{
	//dtor
}

bool E0::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(D) :
			automate.decalageNonTerminal(symbole, new E1);
			return true;
		case(VAR) :
			automate.reduction(R8);
			return true;
		case(CONST) :
			automate.reduction(R8);
			return true;
		case(ECRIRE) :
			automate.reduction(R8);
			return true;
		case(LIRE) :
			automate.reduction(R8);
			return true;
		case(DOL) :
			automate.reduction(R8);
			return true;
		case(ID) :
			automate.reduction(R8);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de syntaxe (attendu : \"var\", \"const\", \"ecrire\", \"lire\", ou id).");
	throw(p);
	return false;
}
