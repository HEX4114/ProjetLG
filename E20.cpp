#include "include/E20.h"
#include "include/Automate.h"

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
			//automate.reduction(...); R19
			return true;
			break;
	}

	return false;
}