#include "include/E25.h"
#include "include/Automate.h"

E25::E25()
{
	//ctor
}

E25::~E25()
{
	//dtor
}

bool E25::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(DOL) :
			//automate.reduction(...);R17
			break;
		
	}
	return false;
}