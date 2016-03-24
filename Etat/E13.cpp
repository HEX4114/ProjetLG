#include "E13.h"
#include "Etat.h"
#include "../Automate.h"

#include "E14.h"
#include "E25.h"

E13::E13()
{
	//ctor
}

E13::~E13()
{
	//dtor
}

bool E13::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(PVG) :
			automate.decalageTerminal(symbole, new E25);
			return true;
		case(PLUS) :
			automate.decalageTerminal(symbole, new E14);
			return true;
		case(MOINS) :
			automate.decalageTerminal(symbole, new E14);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de syntaxe (attendu : \";\", \"+\", ou \"-\").");
	throw(p);
	return false;
}
