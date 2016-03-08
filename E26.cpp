#include "include/E26.h"
#include "include/Automate.h"

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
		case(DOL) :
			//automate.reduction(...);R9
			break;
	
	}
	return false;
}