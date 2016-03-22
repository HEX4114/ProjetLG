#ifndef E12_H
#define E12_H
#include <iostream>
#include <string>

#include "Etat.h"

class E12 : public Etat
{
public:
	E12();
	virtual ~E12();
	virtual bool transition(Automate& automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E12_H
