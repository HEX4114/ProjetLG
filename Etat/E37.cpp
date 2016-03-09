#include "E37.h"
#include "Etat.h"
#include "../Automate.h"

E37::E37()
{
	//ctor
}

E37::~E37()
{
	//dtor
}

bool E37::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(NB) :
			automate.decalage(symbole, new E38);
			break;
	}
	return false;
}