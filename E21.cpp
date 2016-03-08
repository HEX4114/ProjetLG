#include "include/E21.h"
#include "include/Automate.h"

E21::E21()
{
	//ctor
}

E21::~E21()
{
	//dtor
}

bool E21::transition(Automate automate, Symbole symbole) {
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
			//automate.decalage(symbole, new E23);
			break;
		case(T) :
			//automate.decalage(symbole, new E22);
			break;
		case(F) :
			//automate.decalage(symbole, new E18);
			break;
		
	}
	return false;
}