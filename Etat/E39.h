#ifndef E39_H
#define E39_H
#include <iostream>
#include <string>

#include "Etat.h"

class E39 : public Etat
{
public:
	E39();
	virtual ~E39();
	virtual bool transition(Automate& automate, Symbole* symbole);
protected:
	std::string name;
private:
};

#endif // E39_H
