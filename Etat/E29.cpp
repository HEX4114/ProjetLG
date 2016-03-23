#include "E29.h"
#include "Etat.h"
#include "../Automate.h"

E29::E29()
{
	//ctor
}

E29::~E29()
{
	//dtor
}

bool E29::transition(Automate& automate, Symbole* symbole) {
	automate.reduction(R11);
	return true;
}