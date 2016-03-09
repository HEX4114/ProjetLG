#include "E39.h"
#include "Etat.h"
#include "../Automate.h"

E39::E39()
{
	//ctor
}

E39::~E39()
{
	//dtor
}

bool E39::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(DOL) :
			automate.reduction(R7, symbole);
			break;
	}
	return false;
}