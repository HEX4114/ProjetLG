#ifndef E5_H
#define E5_H
#include <iostream>
#include <string>

#include "Etat.h"

class E5 : public Etat
{
public:
	E5();
	virtual ~E5();
	virtual bool transition(Automate& automate, Symbole* symbole);
protected:
	std::string name;
private:
};

#endif // E5_H
