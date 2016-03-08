#include "include/E1.h"
#include "include/Automate.h"

E1::E1()
{
	//ctor
}

E1::~E1()
{
	//dtor
}

bool E1::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
	case(VAR) :
			//automate.decalage(symbole, new E2);
			return true;
			break;
		case(I) :
			//automate.decalage(symbole, new E8);
			return true;
			break;
		case(CONST) :
			//automate.decalage(symbole, new E31);
			return true;
			break;
		case(ECRIRE) :
			//automate.reduction(...); R12
			return true;
			break;
		case(LIRE) : 
			//automate.reduction(...); R12
			return true;
			break;
		case(DOL) :
			//automate.reduction(...); R12
			return true;
			break;
		case(ID) :
			//automate.reduction(...); R12
			return true;
			break;
	}

	return false;
}