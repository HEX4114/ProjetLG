#include "E18.h"
#include "Etat.h"
#include "../Automate.h"

E18::E18()
{
	//ctor
}

E18::~E18()
{
	//dtor
}

bool E18::transition(Automate& automate, Symbole* symbole) {
	automate.reduction(R16);
	return true;
}