#ifndef E7_H
#define E7_H
#include <iostream>
#include <string>

#include "Etat.h"

class E7 : public Etat
{
public:
	E7();
	virtual ~E7();
	virtual bool transition(Automate& automate, Symbole* symbole);
protected:
	std::string name;
private:
};

#endif // E7_H
