#include "include/E32.h"
#include "include/Automate.h"

E32::E32()
{
	//ctor
}

E32::~E32()
{
	//dtor
}

bool E32::transition(Automate automate, Symbole symbole) {
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