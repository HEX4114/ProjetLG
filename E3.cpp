#include "include/E3.h"
#include "include/Automate.h"

E3::E3()
{
	//ctor
}

E3::~E3()
{
	//dtor
}

bool E3::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(V) :
			//automate.decalage(symbole, new E4);
			return true;
			break;
		case(VG) :
			//automate.reduction(...); R3
			return true;
			break;
		case(PVG) :
			//automate.reduction(...); R3
			return true;
			break;
	}

	return false;
}