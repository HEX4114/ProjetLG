#include "E15.h"
#include "Etat.h"
#include "../Automate.h"

#include "E16.h"

E15::E15()
{
	//ctor
}

E15::~E15()
{
	//dtor
}

bool E15::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(MULT) :
			automate.decalageTerminal(symbole, new E16);
			return true;
		case(DIV) :
			automate.decalageTerminal(symbole, new E16);
			return true;
		case(PVG) :
			automate.reduction(R13);
			return true;
		case(PLUS) :
			automate.reduction(R13);
			return true;
		case(MOINS) :
			automate.reduction(R13);
			return true;
		case(PARD) :
			automate.reduction(R13);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de syntaxe (attendu : un opérateur, \")\", ou \";\").");
	throw(p);
	return false;
}
