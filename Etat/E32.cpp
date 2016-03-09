#include "E32.h"
#include "Etat.h"
#include "../Automate.h"

E32::E32()
{
	//ctor
}

E32::~E32()
{
	//dtor
}

bool E32::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(NB) :
			automate.decalage(symbole, new E33);
			break;
	}
	return false;
}