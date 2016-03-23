#include "E8.h"
#include "Etat.h"
#include "../Automate.h"

#include "E9.h"
#include "E12.h"
#include "E26.h"

E8::E8()
{
	//ctor
}

E8::~E8()
{
	//dtor
}

bool E8::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(LIRE) :
			automate.decalageTerminal(symbole, new E9);
			return true;
		case(ECRIRE) :
			automate.decalageTerminal(symbole, new E12);
			return true;
		case(ID) :
			automate.decalageTerminal(symbole, new E26);
			return true;
		case(DOL) :
			automate.accepter();
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de synthaxe (attendu : \"ecrire\", \"lire\", ou id).");
	throw(p);
	return false;
}