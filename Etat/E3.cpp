#include "E3.h"
#include "Etat.h"
#include "../Automate.h"

#include "E4.h"

E3::E3()
{
	//ctor
}

E3::~E3()
{
	//dtor
}

bool E3::transition(Automate& automate, Symbole* symbole) {
	switch (symbole->getType())
	{
		case(V) :
			automate.decalageNonTerminal(symbole, new E4);
			return true;
		case(VG) :
			automate.reduction(R3);
			return true;
		case(PVG) :
			automate.reduction(R3);
			return true;
	}
	automate.reduction(R3);
	return true;
}