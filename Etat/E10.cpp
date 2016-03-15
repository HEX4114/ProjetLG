#include "E10.h"
#include "Etat.h"
#include "../Automate.h"

#include "E11.h"

E10::E10()
{
	//ctor
}

E10::~E10()
{
	//dtor
}

bool E10::transition(Automate automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(PVG) :
			automate.decalage(symbole, new E11);
			return true;
			break;
	}

	return false;
}