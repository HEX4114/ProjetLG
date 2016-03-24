#include "E31.h"
#include "Etat.h"
#include "../Automate.h"

#include "E32.h"

E31::E31()
{
	//ctor
}

E31::~E31()
{
	//dtor
}

bool E31::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(EG) :
			automate.decalageTerminal(symbole, new E32);
			return true;
		case(NB) :
			Symbole* symboleAnticipe = new Symbole();
			symboleAnticipe->setType(EG);
			automate.decalageAnticipe(symboleAnticipe, new E32);
			std::pair<int, string> p = std::make_pair(0, "Erreur syntaxique symbole \"=\" attendu");
			throw(p);
			return true;
	}
	std::pair<int, string> p = std::make_pair(0, "Erreur syntaxique symbole \"=\" attendu");
	throw(p);
	return false;
}
