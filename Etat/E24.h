#ifndef E24_H
#define E24_H
#include <iostream>
#include <string>

#include "Etat.h"

class E24 : public Etat
{
public:
	E24();
	virtual ~E24();
	virtual bool transition(Automate& automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E24_H
