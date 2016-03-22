#include "E25.h"
#include "Etat.h"
#include "../Automate.h"

E25::E25()
{
	//ctor
}

E25::~E25()
{
	//dtor
}

bool E25::transition(Automate& automate, Symbole symbole) {
	automate.reduction(R9);
	return true;
}