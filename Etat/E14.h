#ifndef E14_H
#define E14_H
#include <iostream>
#include <string>

#include "Etat.h"

class E14 : public Etat
{
public:
	E14();
	virtual ~E14();
	virtual bool transition(Automate automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E14_H
