#ifndef E10_H
#define E10_H
#include <iostream>
#include <string>

#include "Etat.h"

class E10 : public Etat
{
public:
	E10();
	virtual ~E10();
	virtual bool transition(Automate& automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E10_H
