#include "E38.h"
#include "Etat.h"
#include "../Automate.h"

E38::E38()
{
	//ctor
}

E38::~E38()
{
	//dtor
}

bool E38::transition(Automate& automate, Symbole* symbole) {
	automate.reduction(R4);
	return true;
}