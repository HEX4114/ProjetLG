#include "include/E27.h"
#include "include/Automate.h"

E27::E27()
{
	//ctor
}

E27::~E27()
{
	//dtor
}

bool E27::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(AF) :
			//automate.decalage(symbole, new E28);
			break;

	}
	return false;
}