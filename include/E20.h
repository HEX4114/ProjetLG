#ifndef E20_H
#define E20_H
#include <iostream>
#include <string>

#include "Etat.h"

class E20 : public Etat
{
public:
	E20();
	virtual ~E20();
	virtual bool transition(Automate automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E20_H
