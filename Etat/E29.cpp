#include "E29.h"
#include "Etat.h"
#include "../Automate.h"

//TODO

E29::E29()
{
	//ctor
}

E29::~E29()
{
	//dtor
}

bool E29::transition(Automate automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(DOL) :
			automate.reduction(R11, symbole);
			break;
		
	}
	return false;
}