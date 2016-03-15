#ifndef E0_H
#define E0_H
#include <iostream>
#include <string>

#include "Etat.h"

class E0 : public Etat
{
public:
	E0();
	virtual ~E0();
	virtual bool transition(Automate& automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E0_H
