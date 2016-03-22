#include "E36.h"
#include "Etat.h"
#include "../Automate.h"

#include "E37.h"

E36::E36()
{
	//ctor
}

E36::~E36()
{
	//dtor
}

bool E36::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(EG) :
			automate.decalageTerminal(symbole, new E37);
			return true;
			break;
	}
	return false;
}