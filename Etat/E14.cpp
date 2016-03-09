#include "E14.h"
#include "Etat.h"
#include "../Automate.h"

#include "E19.h"
#include "E20.h"
#include "E15.h"
#include "E18.h"

E14::E14()
{
	//ctor
}

E14::~E14()
{
	//dtor
}

bool E14::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(ID) :
			automate.decalage(symbole, new E19);
			return true;
			break;
		case(NB) :
			automate.decalage(symbole, new E20);
			return true;
			break;
		case(PARG) :
			automate.decalage(symbole, new E20);
			return true;
			break;
		case(T) :
			automate.decalage(symbole, new E15);
			return true;
			break;
		case(F) :
			automate.decalage(symbole, new E18);
			return true;
			break;
	}

	return false;
}