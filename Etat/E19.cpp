#include "E19.h"
#include "Etat.h"
#include "../Automate.h"

E19::E19()
{
	//ctor
}

E19::~E19()
{
	//dtor
}

bool E19::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>) {
	automate.reduction(R18);
	return true;
}
