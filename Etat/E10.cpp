#include "E10.h"
#include "Etat.h"
#include "../Automate.h"

#include "E11.h"

E10::E10()
{
	//ctor
}

E10::~E10()
{
	//dtor
}

bool E10::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(PVG) :
			automate.decalageTerminal(symbole, new E11);
			return true;
	}
	Symbole* symboleAnticipe = new Symbole();
	symboleAnticipe->setType(PVG);
	automate.decalageAnticipe(symboleAnticipe, new E11);
	std::pair<int, string> p = std::make_pair(0, "Warning : \";\" manquante.");
	throw(p);
	return true;
}