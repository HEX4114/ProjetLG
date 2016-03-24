#include "E21.h"
#include "Etat.h"
#include "../Automate.h"

#include "E19.h"
#include "E20.h"
#include "E22.h"
#include "E18.h"
#include "E23.h"

E21::E21()
{
	//ctor
}

E21::~E21()
{
	//dtor
}

bool E21::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(ID) :
			automate.decalageTerminal(symbole, new E19);
			return true;
		case(NB) :
			automate.decalageTerminal(symbole, new E20);
			return true;
		case(PARG) :
			automate.decalageTerminal(symbole, new E21);
			return true;
		case(E) :
			automate.decalageNonTerminal(symbole, new E23);
			return true;
		case(T) :
			automate.decalageNonTerminal(symbole, new E22);
			return true;
		case(F) :
			automate.decalageNonTerminal(symbole, new E18);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de syntaxe (attendu : \"(\", nombre, id, ou expression).");
	throw(p);
	return false;
}
