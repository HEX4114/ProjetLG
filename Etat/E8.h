#ifndef E8_H
#define E8_H
#include <iostream>
#include <string>

#include "Etat.h"

class E8 : public Etat
{
public:
	E8();
	virtual ~E8();
	virtual bool transition(Automate& automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E8_H
