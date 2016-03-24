#include "E36.h"
#include "Etat.h"
#include "../Automate.h"

#include "E37.h"

E36::E36()
{
	//ctor
}

E36::~E36()
{
	//dtor
}

bool E36::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(EG) :
			automate.decalageTerminal(symbole, new E37);
			return true;
		case(NB) :
			Symbole* symboleAnticipe = new Symbole();
			symboleAnticipe->setType(EG);
			automate.decalageAnticipe(symboleAnticipe, new E37);
			std::pair<int, string> p = std::make_pair(0, "Erreur syntaxique symbole \"=\" attendu");
			throw(p);
			return true;
	}
	std::pair<int, string> p = std::make_pair(0, "Erreur syntaxique symbole \"=\" attendu");
	throw(p);
	return false;
}
