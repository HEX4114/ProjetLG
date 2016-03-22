#include "E2.h"
#include "Etat.h"
#include "../Automate.h"

#include "E3.h"

E2::E2()
{
	//ctor
}

E2::~E2()
{
	//dtor
}

bool E2::transition(Automate& automate, Symbole symbole) throw(std::pair<int, string>) {
	switch (symbole.getType())
	{
		case(ID) :
			automate.decalageTerminal(symbole, new E3);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de synthaxe (id manquant).");
	throw(p);
	return false;
}