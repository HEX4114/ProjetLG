#include "include/E2.h"
#include "include/Automate.h"

E2::E2()
{
	//ctor
}

E2::~E2()
{
	//dtor
}

bool E2::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(ID) :
			//automate.decalage(symbole, new E3);
			return true;
			break;
	}

	return false;
}