#include "E22.h"
#include "../Automate.h"

E22::E22()
{
	//ctor
}

E22::~E22()
{
	//dtor
}

bool E22::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(PVG) :
			//automate.reduction(...);R14
			break;
		case(I) :
			//automate.reduction(...);R14
			break;
		case(OPM) :
			//automate.decalage(symbole, new E16);
			break;
		case(PARD) :
			//automate.reduction(...);R14
			break;
		
	}
	return false;
}