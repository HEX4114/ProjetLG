#include "E26.h"
#include "Etat.h"
#include "../Automate.h"

#include "E27.h"

E26::E26()
{
	//ctor
}

E26::~E26()
{
	//dtor
}

bool E26::transition(Automate& automate, Symbole *symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(AF) :
			automate.decalageTerminal(symbole, new E27);
			return true;
		case(ID) :
		case(NB) :
		case(PARG) :
		case(E) :
		case(F) :
		case(T) :
			Symbole* symboleAnticipe = new Symbole();
			symboleAnticipe->setType(AF);
			automate.decalageAnticipe(symboleAnticipe, new E27);
			std::pair<int, string> p = std::make_pair(0, "Erreur syntaxique symbole \":=\" attendu");
			throw(p);
			return true;
	}
	std::pair<int, string> p = std::make_pair(0, "Erreur syntaxique symbole \":=\" attendu");
	throw(p);
	return false;
}
