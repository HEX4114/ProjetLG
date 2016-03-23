#include "E37.h"
#include "Etat.h"
#include "../Automate.h"

#include "E38.h"

E37::E37()
{
	//ctor
}

E37::~E37()
{
	//dtor
}

bool E37::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(NB) :
			automate.decalageTerminal(symbole, new E38);
			return true;
	}
	std::pair<int, string> p = std::make_pair(1, "Erreur de synthaxe (attendu : nombre).");
	throw(p);
	return false;
}