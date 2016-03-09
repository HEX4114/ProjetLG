#include "E13.h"
#include "Etat.h"
#include "../Automate.h"

E13::E13()
{
	//ctor
}

E13::~E13()
{
	//dtor
}

bool E13::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(PVG) :
			automate.decalage(symbole, new E25);
			return true;
			break;
		case(OPA) :
			automate.decalage(symbole, new E14);
			return true;
			break;
	}

	return false;
}