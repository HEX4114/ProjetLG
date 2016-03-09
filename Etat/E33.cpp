#include "E33.h"
#include "Etat.h"
#include "../Automate.h"

#include "E34.h"

E33::E33()
{
	//ctor
}

E33::~E33()
{
	//dtor
}

bool E33::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(VG) :
			automate.reduction(R5, symbole);
			break;
		case(PVG) :
			automate.reduction(R5, symbole);
			break;
		case(C) :
			automate.decalage(symbole, new E34);
			break;		
	}
	return false;
}