#ifndef E27_H
#define E27_H
#include <iostream>
#include <string>

#include "Etat.h"

class E27 : public Etat
{
public:
	E27();
	virtual ~E27();
	virtual bool transition(Automate& automate, Symbole* symbole);
protected:
	std::string name;
private:
};

#endif // E27_H
