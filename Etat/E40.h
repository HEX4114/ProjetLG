#ifndef E40_H
#define E40_H
#include <iostream>
#include <string>

#include "Etat.h"

class E40 : public Etat
{
public:
	E40();
	virtual ~E40();
	virtual bool transition(Automate automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E40_H
