#include "E37.h"
#include "Etat.h"
#include "../Automate.h"

#include "E38.h"

E37::E37()
{
	//ctor
}

E37::~E37()
{
	//dtor
}

bool E37::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(NB) :
			automate.decalage(symbole, new E38);
			break;
	}
	return false;
}