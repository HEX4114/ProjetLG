#include "include/E11.h"
#include "include/Automate.h"

E11::E11()
{
	//ctor
}

E11::~E11()
{
	//dtor
}

bool E11::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(DOL) :
			//automate.reduction(...); R10
			return true;
			break;
	}

	return false;
}