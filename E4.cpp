#include "include/E4.h"
#include "include/Automate.h"

E4::E4()
{
	//ctor
}

E4::~E4()
{
	//dtor
}

bool E4::transition(Automate automate, Symbole symbole) {
	switch (symbole.getId())
	{
		case(VG) :
			//automate.decalage(symbole, new E6);
			return true;
			break;
		case(PVG) :
			//automate.decalage(symbole, new E5);
			return true;
			break;
	}

	return false;
}