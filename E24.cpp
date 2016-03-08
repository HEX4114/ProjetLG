#include "include/E24.h"
#include "include/Automate.h"

E24::E24()
{
	//ctor
}

E24::~E24()
{
	//dtor
}

bool E24::transition(Automate automate, Symbole symbole) {
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
		case(F) :
			//automate.decalage(symbole, new E18);
			break;
		
	}
	return false;
}