#ifndef E13_H
#define E13_H
#include <iostream>
#include <string>

#include "Etat.h"

class E13 : public Etat
{
public:
	E13();
	virtual ~E13();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E13_H
