#include "E23.h"
#include "../Automate.h"

E23::E23()
{
	//ctor
}

E23::~E23()
{
	//dtor
}

bool E23::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(OPA) :
			//automate.decalage(symbole, new E24);
			break;
		case(PARD) :
			//automate.decalage(symbole, new E25);
			break;
		
	}
	return false;
}