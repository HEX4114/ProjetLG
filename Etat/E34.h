#ifndef E34_H
#define E34_H
#include <iostream>
#include <string>

#include "Etat.h"

class E34 : public Etat
{
public:
	E34();
	virtual ~E34();
	virtual bool transition(Automate& automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E34_H
