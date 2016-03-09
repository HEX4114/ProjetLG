#include "E27.h"
#include "Etat.h"
#include "../Automate.h"

E27::E27()
{
	//ctor
}

E27::~E27()
{
	//dtor
}

bool E27::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(ID) :
			automate.decalage(symbole, new E19);
			break;
		case(NB) :
			automate.decalage(symbole, new E20);
			break;
		case(PARG) :
			automate.decalage(symbole, new E21);
			break;
		case(E) :
			automate.decalage(symbole, new E28);
			break;
		case(T) :
			automate.decalage(symbole, new E22);
			break;
		case(F) :
			automate.decalage(symbole, new E18);
			break;

	}
	return false;
}