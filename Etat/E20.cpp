#include "E20.h"
#include "Etat.h"
#include "../Automate.h"

E20::E20()
{
	//ctor
}

E20::~E20()
{
	//dtor
}

bool E20::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(DOL) :
			automate.reduction(R19, symbole);
			return true;
			break;
	}

	return false;
}