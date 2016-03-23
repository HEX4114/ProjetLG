#ifndef E4_H
#define E4_H
#include <iostream>
#include <string>

#include "Etat.h"

class E4 : public Etat
{
public:
	E4();
	virtual ~E4();
	virtual bool transition(Automate& automate, Symbole* symbole);
protected:
	std::string name;
private:
};

#endif // E4_H
