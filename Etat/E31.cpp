#include "E31.h"
#include "../Automate.h"

E31::E31()
{
	//ctor
}

E31::~E31()
{
	//dtor
}

bool E31::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(VAR) :
			//automate.decalage(symbole, new E2);
			break;
		case(I) :
			//automate.decalage(symbole, new E8);
			break;
		case(CONST) :
			//automate.decalage(symbole, new E31);
			break;
		case(ECRIRE) :
			//automate.reduction(...);
			break;
		case(LIRE) :
			//automate.reduction(...);
			break;
		case(DOL) :
			//automate.reduction(...);
			break;
		case(ID) :
			//automate.reduction(...);
			break;
		
	}
	return false;
}