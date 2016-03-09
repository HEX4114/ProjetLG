#include "E5.h"
#include "Etat.h"
#include "../Automate.h"

E5::E5()
{
	//ctor
}

E5::~E5()
{
	//dtor
}

bool E5::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(P) :
			automate.reduction(R6, symbole);
			return true;
			break;
	}

	return false;
}