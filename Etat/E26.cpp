#include "E26.h"
#include "Etat.h"
#include "../Automate.h"

E26::E26()
{
	//ctor
}

E26::~E26()
{
	//dtor
}

bool E26::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(AF) :
			automate.decalage(symbole, new E27);
			break;
	}
	return false;
}