#include "E36.h"
#include "Etat.h"
#include "../Automate.h"

E36::E36()
{
	//ctor
}

E36::~E36()
{
	//dtor
}

bool E36::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(EG) :
			automate.decalage(symbole, new E37);
			break;
	}
	return false;
}