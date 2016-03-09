#include "E16.h"
#include "Etat.h"
#include "../Automate.h"

#include "E19.h"
#include "E21.h"
#include "E20.h"
#include "E17.h"

E16::E16()
{
	//ctor
}

E16::~E16()
{
	//dtor
}

bool E16::transition(Automate automate, Symbole symbole) {
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
			automate.decalage(symbole, new E21);
			return true;
			break;
		case(F) :
			automate.decalage(symbole, new E17);
			return true;
			break;
	}

	return false;
}