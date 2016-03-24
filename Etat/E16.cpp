#include "E16.h"
#include "Etat.h"
#include "../Automate.h"

#include "E19.h"
#include "E21.h"
#include "E20.h"
#include "E17.h"

E16::E16()
{
	//ctor
}

E16::~E16()
{
	//dtor
}

bool E16::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
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
		case(F) :
			automate.decalageNonTerminal(symbole, new E17);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de synthaxe (attendu : \"(\", nombre, id, ou expression).");
	throw(p);
	return false;
}
