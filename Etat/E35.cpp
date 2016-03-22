#include "E35.h"
#include "Etat.h"
#include "../Automate.h"

#include "E36.h"

E35::E35()
{
	//ctor
}

E35::~E35()
{
	//dtor
}

bool E35::transition(Automate& automate, Symbole symbole) throw(std::pair<int, string>) {
	switch (symbole.getType())
	{
		case(ID) :
			automate.decalageTerminal(symbole, new E36);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de synthaxe (attendu : identifiant).");
	throw(p);
	return false;
}