#include "E33.h"
#include "Etat.h"
#include "../Automate.h"

#include "E34.h"

E33::E33()
{
	//ctor
}

E33::~E33()
{
	//dtor
}

bool E33::transition(Automate& automate, Symbole symbole) throw(std::pair<int, string>) {
	switch (symbole.getType())
	{
		case(VG) :
			automate.reduction(R5);
			return true;
		case(PVG) :
			automate.reduction(R5);
			return true;
		case(C) :
			automate.decalageNonTerminal(symbole, new E34);
			return true;
	}
	automate.reduction(R5);
	return false;
}