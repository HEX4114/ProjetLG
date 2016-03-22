#ifndef E21_H
#define E21_H
#include <iostream>
#include <string>

#include "Etat.h"

class E21 : public Etat
{
public:
	E21();
	virtual ~E21();
	virtual bool transition(Automate& automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E21_H
