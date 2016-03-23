#ifndef E2_H
#define E2_H
#include <iostream>
#include <string>

#include "Etat.h"

class E2 : public Etat
{
public:
	E2();
	virtual ~E2();
	virtual bool transition(Automate& automate, Symbole* symbole);
protected:
	std::string name;
private:
};

#endif // E2_H
