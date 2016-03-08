#include "include/E17.h"
#include "include/Automate.h"

E17::E17()
{
	//ctor
}

E17::~E17()
{
	//dtor
}

bool E17::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(DOL) :
			//automate.reduction(...); R15
			return true;
			break;
	}

	return false;
}