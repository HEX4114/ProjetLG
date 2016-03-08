#include "include/E28.h"
#include "include/Automate.h"

E28::E28()
{
	//ctor
}

E28::~E28()
{
	//dtor
}

bool E28::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(ID) :
			//automate.decalage(symbole, new E19);
			break;
		case(NB) :
			//automate.decalage(symbole, new E20);
			break;
		case(PARG) :
			//automate.decalage(symbole, new E21);
			break;
		case(E) :
			//automate.decalage(symbole, new E29);
			break;
		case(T) :
			//automate.decalage(symbole, new E22);
			break;
		case(F) :
			//automate.decalage(symbole, new E14);
			break;
		
	}
	return false;
}