#include "E30.h"
#include "Etat.h"
#include "../Automate.h"

#include "E31.h"

E30::E30()
{
	//ctor
}

E30::~E30()
{
	//dtor
}

bool E30::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(ID) :
			automate.decalage(symbole, new E31);
			break;
	}
	return false;
}