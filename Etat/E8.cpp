#include "E8.h"
#include "Etat.h"
#include "../Automate.h"

E8::E8()
{
	//ctor
}

E8::~E8()
{
	//dtor
}

bool E8::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(LIRE) :
			automate.decalage(symbole, new E9);
			return true;
			break;
		case(ECRIRE) :
			automate.decalage(symbole, new E12);
			return true;
			break;
		case(ID) :
			automate.decalage(symbole, new E26);
			return true;
			break;
		case(P) :
			//automate.accept(...);
			return true;
			break;
	}

	return false;
}