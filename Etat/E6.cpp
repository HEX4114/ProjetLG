#include "E6.h"
#include "Etat.h"
#include "../Automate.h"

#include "E7.h"

E6::E6()
{
	//ctor
}

E6::~E6()
{
	//dtor
}

bool E6::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(ID) :
			automate.decalageTerminal(symbole, new E7);
			return true;
			break;

	}

	return false;
}