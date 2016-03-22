#ifndef E3_H
#define E3_H
#include <iostream>
#include <string>

#include "Etat.h"

class E3 : public Etat
{
public:
	E3();
	virtual ~E3();
	virtual bool transition(Automate& automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E3_H
