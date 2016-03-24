#ifndef E6_H
#define E6_H
#include <iostream>
#include <string>

#include "Etat.h"

class E6 : public Etat
{
public:
	E6();
	virtual ~E6();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E6_H
