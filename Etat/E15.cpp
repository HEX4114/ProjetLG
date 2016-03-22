#include "E15.h"
#include "Etat.h"
#include "../Automate.h"

#include "E16.h"

E15::E15()
{
	//ctor
}

E15::~E15()
{
	//dtor
}

bool E15::transition(Automate& automate, Symbole symbole) {
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
			automate.reduction(R13);
			return true;
			break;
		case(PLUS) :
			automate.reduction(R13);
			return true;
			break;
		case(MOINS) :
			automate.reduction(R13);
			return true;
			break;
		case(PARD) :
			automate.reduction(R13);
			return true;
			break;
	}

	return false;
}