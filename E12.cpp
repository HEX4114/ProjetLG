#include "include/E12.h"
#include "include/Automate.h"

E12::E12()
{
	//ctor
}

E12::~E12()
{
	//dtor
}

bool E12::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
	case(ID) :
			//automate.decalage(symbole, new E19);
			return true;
			break;
		case(NB) :
			//automate.decalage(symbole, new E20);
			return true;
			break;
		case(PARG) :
			//automate.decalage(symbole, new E21);
			return true;
			break;
		case(E) :
			//automate.decalage(symbole, new E13);
			return true;
			break;
		case(T) :
			//automate.decalage(symbole, new E22);
			return true;
			break;
		case(F) :
			//automate.decalage(symbole, new E18);
			return true;
			break;
	}

	return false;
}