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

bool E34::transition(Automate& automate, Symbole symbole) throw(std::pair<int, string>) {
	switch (symbole.getType())
	{
		case(VG) :
			automate.decalageTerminal(symbole, new E35);
			return true;
		case(PVG) :
			automate.decalageTerminal(symbole, new E39);
			return true;
		case(ID) :
			Symbole symboleAnticipe = Symbole();
			symboleAnticipe.setType(VG);
			automate.decalageAnticipe(symboleAnticipe, new E35);
			std::pair<int, string> p = std::make_pair(0, "Warning : \",\" manquante.");
			throw(p);
			return true;
	}
	Symbole symboleAnticipe = Symbole();
	symboleAnticipe.setType(PVG);
	automate.decalageAnticipe(symboleAnticipe, new E39);
	std::pair<int, string> p = std::make_pair(0, "Warning : \";\" manquant.");
	throw(p);

	return false;
}