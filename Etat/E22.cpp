#include "E22.h"
#include "Etat.h"
#include "../Automate.h"

#include "E16.h"

E22::E22()
{
	//ctor
}

E22::~E22()
{
	//dtor
}

bool E22::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(MULT) :
			automate.decalageTerminal(symbole, new E16);
			return true;
			break;
		case(DIV) :
			automate.decalageTerminal(symbole, new E16);
			return true;
			break;
		case(PVG) :
			automate.reduction(R14);
			return true;
			break;
		case(PLUS) :
			automate.reduction(R14);
			return true;
			break;
		case(MOINS) :
			automate.reduction(R14);
			return true;
			break;
		case(PARD) :
			automate.reduction(R14);
			return true;
			break;
	}
	return false;
}