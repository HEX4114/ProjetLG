#ifndef E23_H
#define E23_H
#include <iostream>
#include <string>

#include "Etat.h"

class E23 : public Etat
{
public:
	E23();
	virtual ~E23();
	virtual bool transition(Automate& automate, Symbole* symbole);
protected:
	std::string name;
private:
};

#endif // E23_H
