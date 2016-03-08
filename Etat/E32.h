#ifndef E32_H
#define E32_H
#include <iostream>
#include <string>

#include "Etat.h"

class E32 : public Etat
{
public:
	E32();
	virtual ~E32();
	virtual bool transition(Automate automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E32_H
