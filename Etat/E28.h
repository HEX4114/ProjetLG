#ifndef E28_H
#define E28_H
#include <iostream>
#include <string>

#include "Etat.h"

class E28 : public Etat
{
public:
	E28();
	virtual ~E28();
	virtual bool transition(Automate& automate, Symbole* symbole);
protected:
	std::string name;
private:
};

#endif // E28_H
