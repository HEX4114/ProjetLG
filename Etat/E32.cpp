#include "E32.h"
#include "Etat.h"
#include "../Automate.h"

#include "E33.h"

E32::E32()
{
	//ctor
}

E32::~E32()
{
	//dtor
}

bool E32::transition(Automate& automate, Symbole symbole) throw(std::pair<int, string>) {
	switch (symbole.getType())
	{
		case(NB) :
			automate.decalageTerminal(symbole, new E33);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de synthaxe (attendu : nombre).");
	throw(p);
	return false;
}