#include "E7.h"
#include "Etat.h"
#include "../Automate.h"

E7::E7()
{
	//ctor
}

E7::~E7()
{
	//dtor
}

bool E7::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(ECRIRE) :
			automate.reduction(R2, symbole);
			return true;
			break;
	}

	return false;
}