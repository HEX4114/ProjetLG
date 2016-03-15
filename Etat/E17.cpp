#include "E17.h"
#include "Etat.h"
#include "../Automate.h"

E17::E17()
{
	//ctor
}

E17::~E17()
{
	//dtor
}

bool E17::transition(Automate automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(DOL) :
			automate.reduction(R15, symbole);
			return true;
			break;
	}

	return false;
}