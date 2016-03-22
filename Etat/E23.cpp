#include "E23.h"
#include "Etat.h"
#include "../Automate.h"

#include "E14.h"
#include "E24.h"

E23::E23()
{
	//ctor
}

E23::~E23()
{
	//dtor
}

bool E23::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(PLUS) :
			automate.decalageTerminal(symbole, new E14);
			return true;
			break;
		case(MOINS) :
			automate.decalageTerminal(symbole, new E14);
			return true;
			break;
		case(PARD) :
			automate.decalageTerminal(symbole, new E24);
			return true;
			break;
		
	}
	return false;
}