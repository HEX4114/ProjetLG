#ifndef E18_H
#define E18_H
#include <iostream>
#include <string>

#include "Etat.h"

class E18 : public Etat
{
public:
	E18();
	virtual ~E18();
	virtual bool transition(Automate& automate, Symbole symbole);
protected:
	std::string name;
private:
};

#endif // E18_H
