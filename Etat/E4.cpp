#include "E4.h"
#include "Etat.h"
#include "../Automate.h"


#include "E5.h"
#include "E6.h"

E4::E4()
{
	//ctor
}

E4::~E4()
{
	//dtor
}

bool E4::transition(Automate& automate, Symbole* symbole) throw(std::pair<int, string>) {
	switch (symbole->getType())
	{
		case(VG) :
			automate.decalageTerminal(symbole, new E6);
			return true;
		case(PVG) :
			automate.decalageTerminal(symbole, new E5);
			return true;
		case(ID) :
			Symbole *symboleAnticipe = new Symbole();
			symboleAnticipe->setType(VG);
			automate.decalageAnticipe(symboleAnticipe, new E6);
			std::pair<int, string> p = std::make_pair(0, "Erreur syntaxique symbole \",\" attendu");
			throw(p);
			return true;
	}
	Symbole* symboleAnticipe = new Symbole();
	symboleAnticipe->setType(PVG);
	automate.decalageAnticipe(symboleAnticipe, new E5);
	std::pair<int, string> p = std::make_pair(0, "Erreur syntaxique symbole \";\" attendu");
	throw(p);

	return true;
}
