#ifndef E19_H
#define E19_H
#include <iostream>
#include <string>

#include "Etat.h"

class E19 : public Etat
{
public:
	E19();
	virtual ~E19();
	virtual bool transition(Automate automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E19_H
