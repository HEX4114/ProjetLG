#ifndef E30_H
#define E30_H
#include <iostream>
#include <string>

#include "Etat.h"

class E30 : public Etat
{
public:
	E30();
	virtual ~E30();
	virtual bool transition(Automate& automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E30_H
