#include "E13.h"
#include "Etat.h"
#include "../Automate.h"

#include "E14.h"
#include "E25.h"

E13::E13()
{
	//ctor
}

E13::~E13()
{
	//dtor
}

bool E13::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(PVG) :
			automate.decalageTerminal(symbole, new E25);
			return true;
			break;
		case(PLUS) :
			automate.decalageTerminal(symbole, new E14);
			return true;
			break;
		case(MOINS) :
			automate.decalageTerminal(symbole, new E14);
			return true;
			break;
	}

	return false;
}