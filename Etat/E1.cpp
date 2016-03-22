#include "E1.h"
#include "Etat.h"
#include "../Automate.h"

#include "E2.h"
#include "E8.h"
#include "E30.h"

E1::E1()
{
	//ctor
}

E1::~E1()
{
	//dtor
}

bool E1::transition(Automate& automate, Symbole symbole) throw(std::pair<int, string>) {
	switch (symbole.getType())
	{
		case(VAR) :
			automate.decalageTerminal(symbole, new E2);
			return true;
		case(I) :
			automate.decalageNonTerminal(symbole, new E8);
			return true;
		case(CONST) :
			automate.decalageTerminal(symbole, new E30);
			return true;
		case(ECRIRE) :
			automate.reduction(R12);
			return true;
		case(LIRE) : 
			automate.reduction(R12);
			return true;
		case(DOL) :
			automate.reduction(R12);
			return true;
		case(ID) :
			automate.reduction(R12);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de synthaxe (attendu : \"var\", \"const\", \"ecrire\", \"lire\", ou id).");
	throw(p);
	return false;
}