#include "E26.h"
#include "Etat.h"
#include "../Automate.h"

#include "E27.h"

E26::E26()
{
	//ctor
}

E26::~E26()
{
	//dtor
}

bool E26::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(AF) :
			automate.decalageTerminal(symbole, new E27);
			return true;
			break;
	}
	return false;
}