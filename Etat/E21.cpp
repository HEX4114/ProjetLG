#include "E21.h"
#include "Etat.h"
#include "../Automate.h"

#include "E19.h"
#include "E20.h"
#include "E22.h"
#include "E18.h"
#include "E23.h"

E21::E21()
{
	//ctor
}

E21::~E21()
{
	//dtor
}

bool E21::transition(Automate& automate, Symbole symbole) {
	switch (symbole.getType())
	{
		case(ID) :
			automate.decalageTerminal(symbole, new E19);
			return true;
			break;
		case(NB) :
			automate.decalageTerminal(symbole, new E20);
			return true;
			break;
		case(PARG) :
			automate.decalageTerminal(symbole, new E21);
			return true;
			break;
		case(E) :
			automate.decalageNonTerminal(symbole, new E23);
			return true;
			break;
		case(T) :
			automate.decalageNonTerminal(symbole, new E22);
			return true;
			break;
		case(F) :
			automate.decalageNonTerminal(symbole, new E18);
			return true;
			break;
		
	}
	return false;
}