#include "E34.h"
#include "Etat.h"
#include "../Automate.h"

E34::E34()
{
	//ctor
}

E34::~E34()
{
	//dtor
}

bool E34::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(VG) :
			automate.decalage(symbole, new E35);
			break;
		case(PVG) :
			automate.decalage(symbole, new E39);
			break;
	}
	return false;
}