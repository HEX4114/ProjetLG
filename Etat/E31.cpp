#include "E31.h"
#include "Etat.h"
#include "../Automate.h"

#include "E32.h"

E31::E31()
{
	//ctor
}

E31::~E31()
{
	//dtor
}

bool E31::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(EG) :
			automate.decalageTerminal(symbole, new E32);
			return true;
			break;
	}
	return false;
}