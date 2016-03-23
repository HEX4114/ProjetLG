#include "E5.h"
#include "Etat.h"
#include "../Automate.h"

E5::E5()
{
	//ctor
}

E5::~E5()
{
	//dtor
}

bool E5::transition(Automate& automate, Symbole* symbole) {
	automate.reduction(R6);
	return true;
}