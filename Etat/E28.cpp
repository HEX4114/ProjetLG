#include "E28.h"
#include "Etat.h"
#include "../Automate.h"

#include "E14.h"
#include "E29.h"

E28::E28()
{
	//ctor
}

E28::~E28()
{
	//dtor
}

bool E28::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(PVG) :
			automate.decalageTerminal(symbole, new E29);
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