#include "include/E38.h"
#include "include/Automate.h"

E38::E38()
{
	//ctor
}

E38::~E38()
{
	//dtor
}

bool E38::transition(Automate automate, Symbole symbole) {
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