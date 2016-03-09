#include "E38.h"
#include "Etat.h"
#include "../Automate.h"

E38::E38()
{
	//ctor
}

E38::~E38()
{
	//dtor
}

bool E38::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(DOL) :
			automate.reduction(R4, symbole);
			break;
	}
	return false;
}