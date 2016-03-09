#include "E9.h"
#include "Etat.h"
#include "../Automate.h"

E9::E9()
{
	//ctor
}

E9::~E9()
{
	//dtor
}

bool E9::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(ID) :
			automate.decalage(symbole, new E10);
			return true;
			break;
	}

	return false;
}