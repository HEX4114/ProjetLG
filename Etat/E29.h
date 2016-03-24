#ifndef E29_H
#define E29_H
#include <iostream>
#include <string>

#include "Etat.h"

class E29 : public Etat
{
public:
	E29();
	virtual ~E29();
	virtual bool transition(Automate& automate, Symbole* symbole);
protected:
	std::string name;
private:
};

#endif // E29_H
