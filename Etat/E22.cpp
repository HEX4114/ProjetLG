#include "E22.h"
#include "Etat.h"
#include "../Automate.h"

#include "E16.h"

E22::E22()
{
	//ctor
}

E22::~E22()
{
	//dtor
}

bool E22::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(OPM) :
			automate.decalage(symbole, new E16);
			break;
		case(PVG) :
			automate.reduction(R14, symbole);
			break;
		case(OPA) :
			automate.reduction(R14, symbole);
			break;
		case(PARD) :
			automate.reduction(R14, symbole);
			break;
	}
	return false;
}