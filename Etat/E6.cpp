#include "E6.h"
#include "Etat.h"
#include "../Automate.h"

E6::E6()
{
	//ctor
}

E6::~E6()
{
	//dtor
}

bool E6::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(ID) :
			automate.decalage(symbole, new E7);
			return true;
			break;

	}

	return false;
}