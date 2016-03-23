#include "E14.h"
#include "Etat.h"
#include "../Automate.h"

#include "E19.h"
#include "E20.h"
#include "E15.h"
#include "E18.h"

E14::E14()
{
	//ctor
}

E14::~E14()
{
	//dtor
}

bool E14::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>)  {
	switch (symbole->getType())
	{
		case(ID) :
			automate.decalageTerminal(symbole, new E19);
			return true;
		case(NB) :
			automate.decalageTerminal(symbole, new E20);
			return true;
		case(PARG) :
			automate.decalageTerminal(symbole, new E20);
			return true;
		case(T) :
			automate.decalageNonTerminal(symbole, new E15);
			return true;
		case(F) :
			automate.decalageNonTerminal(symbole, new E18);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de synthaxe (attendu : \"(\", nombre, id, ou expression).");
	throw(p);
	return false;
}