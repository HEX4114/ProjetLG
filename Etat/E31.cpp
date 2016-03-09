#include "E31.h"
#include "Etat.h"
#include "../Automate.h"

E31::E31()
{
	//ctor
}

E31::~E31()
{
	//dtor
}

bool E31::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(EG) :
			automate.decalage(symbole, new E32);
			break;
	}
	return false;
}