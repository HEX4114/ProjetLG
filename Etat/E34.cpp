#include "E34.h"
#include "Etat.h"
#include "../Automate.h"

#include "E35.h"
#include "E39.h"

E34::E34()
{
	//ctor
}

E34::~E34()
{
	//dtor
}

bool E34::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(VG) :
			automate.decalage(symbole, new E35);
			return true;
			break;
		case(PVG) :
			automate.decalage(symbole, new E39);
			return true;
			break;
	}
	return false;
}