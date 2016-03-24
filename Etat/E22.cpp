#include "E22.h"
#include "Etat.h"
#include "../Automate.h"

#include "E16.h"

E22::E22()
{
	//ctor
}

E22::~E22()
{
	//dtor
}

bool E22::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(MULT) :
			automate.decalageTerminal(symbole, new E16);
			return true;
		case(DIV) :
			automate.decalageTerminal(symbole, new E16);
			return true;
		case(PVG) :
			automate.reduction(R14);
			return true;
		case(PLUS) :
			automate.reduction(R14);
			return true;
		case(MOINS) :
			automate.reduction(R14);
			return true;
		case(PARD) :
			automate.reduction(R14);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de syntaxe (attendu : un opérateur, \")\", ou \";\").");
	throw(p);
	return false;
}
