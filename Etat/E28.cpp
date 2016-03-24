#include "E28.h"
#include "Etat.h"
#include "../Automate.h"

#include "E14.h"
#include "E29.h"

E28::E28()
{
	//ctor
}

E28::~E28()
{
	//dtor
}

bool E28::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(PLUS) :
			automate.decalageTerminal(symbole, new E14);
			return true;
		case(MOINS) :
			automate.decalageTerminal(symbole, new E14);
			return true;
		case(PVG) :
			automate.decalageTerminal(symbole, new E29);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de syntaxe (attendu : \"+\", \"-\" ou \";\").");
	throw(p);
	return false;
}
