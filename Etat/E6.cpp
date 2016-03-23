#include "E6.h"
#include "Etat.h"
#include "../Automate.h"

#include "E7.h"

E6::E6()
{
	//ctor
}

E6::~E6()
{
	//dtor
}

bool E6::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(ID) :
			automate.decalageTerminal(symbole, new E7);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de synthaxe (id manquant).");
	throw(p);
	return false;
}