#include "E35.h"
#include "Etat.h"
#include "../Automate.h"

#include "E36.h"

E35::E35()
{
	//ctor
}

E35::~E35()
{
	//dtor
}

bool E35::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(ID) :
			automate.decalage(symbole, new E36);
			return true;
			break;
	}
	return false;
}