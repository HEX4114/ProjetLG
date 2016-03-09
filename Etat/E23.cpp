#include "E23.h"
#include "Etat.h"
#include "../Automate.h"

E23::E23()
{
	//ctor
}

E23::~E23()
{
	//dtor
}

bool E23::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(OPA) :
			automate.decalage(symbole, new E14);
			break;
		case(PARD) :
			automate.decalage(symbole, new E24);
			break;
		
	}
	return false;
}