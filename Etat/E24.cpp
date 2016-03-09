#include "E24.h"
#include "Etat.h"
#include "../Automate.h"

E24::E24()
{
	//ctor
}

E24::~E24()
{
	//dtor
}

bool E24::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(DOL) :
			automate.reduction(R17, symbole);
			break;
	}
	return false;
}