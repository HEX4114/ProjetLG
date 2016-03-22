#include "E11.h"
#include "Etat.h"
#include "../Automate.h"

E11::E11()
{
	//ctor
}

E11::~E11()
{
	//dtor
}

bool E11::transition(Automate& automate, Symbole symbole) {
	automate.reduction(R10);
	return true;
}