#ifndef E24_H
#define E24_H
#include <iostream>
#include <string>

#include "Etat.h"

class E1 : public Etat
{
public:
	E1();
	virtual ~E1();
	virtual bool transition(Automate automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E24_H
