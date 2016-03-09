#include "E28.h"
#include "Etat.h"
#include "../Automate.h"

#include "E14.h"
#include "E29.h"

E28::E28()
{
	//ctor
}

E28::~E28()
{
	//dtor
}

bool E28::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(PVG) :
			automate.decalage(symbole, new E29);
			break;
		case(OPA) :
			automate.decalage(symbole, new E14);
			break;
	}
	return false;
}