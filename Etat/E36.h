#ifndef E36_H
#define E36_H
#include <iostream>
#include <string>

#include "Etat.h"

class E36 : public Etat
{
public:
	E36();
	virtual ~E36();
	virtual bool transition(Automate& automate, Symbole* symbole);
protected:
	std::string name;
private:
};

#endif // E36_H
