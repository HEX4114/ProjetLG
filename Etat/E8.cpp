#include "E8.h"
#include "Etat.h"
#include "../Automate.h"

#include "E9.h"
#include "E12.h"
#include "E26.h"

E8::E8()
{
	//ctor
}

E8::~E8()
{
	//dtor
}

bool E8::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
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
		case(DOL) :
			automate.accepter();
			return true;
			break;
	}

	return false;
}