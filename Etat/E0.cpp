#include "E0.h"
#include "Etat.h"
#include "../Automate.h"

#include "E1.h"

E0::E0()
{
	//ctor
}

E0::~E0()
{
	//dtor
}

bool E0::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(D) :
			automate.decalage(symbole, new E1);
			return true;
			break;
		case(VAR) :
			automate.reduction(R8);
			return true;
			break;
		case(CONST) :
			automate.reduction(R8);
			return true;
			break;
		case(ECRIRE) :
			automate.reduction(R8);
			return true;
			break;
		case(LIRE) :
			automate.reduction(R8);
			return true;
			break;
		case(DOL) :
			automate.reduction(R8);
			return true;
			break;
		case(ID) :
			automate.reduction(R8);
			return true;
			break;
	}

	return false;
}