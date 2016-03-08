#include "include/E19.h"
#include "include/Automate.h"

E19::E19()
{
	//ctor
}

E19::~E19()
{
	//dtor
}

bool E19::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(DOL) :
			//automate.reduction(...); R18
			return true;
			break;
	}

	return false;
}