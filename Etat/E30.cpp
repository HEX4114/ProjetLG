#include "E30.h"
#include "Etat.h"
#include "../Automate.h"

#include "E31.h"

E30::E30()
{
	//ctor
}

E30::~E30()
{
	//dtor
}

bool E30::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(ID) :
			automate.decalageTerminal(symbole, new E31);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de syntaxe (attendu : identifiant).");
	throw(p);
	return false;
}
