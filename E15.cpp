#include "include/E15.h"
#include "include/Automate.h"

E15::E15()
{
	//ctor
}

E15::~E15()
{
	//dtor
}

bool E15::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(OPM) :
			//automate.decalage(symbole, new E16);
			return true;
			break;
		case(PVG) :
			//automate.reduction(...); R13
			return true;
			break;
		case(OPA) :
			//automate.reduction(...); R13
			return true;
			break;
		case(PARD) :
			//automate.reduction(...); R13
			return true;
			break;
	}

	return false;
}