#ifndef E31_H
#define E31_H
#include <iostream>
#include <string>

#include "Etat.h"

class E31 : public Etat
{
public:
	E31();
	virtual ~E31();
	virtual bool transition(Automate& automate, Symbole* symbole);
protected:
	std::string name;
private:
};

#endif // E31_H
