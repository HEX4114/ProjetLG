#ifndef E35_H
#define E35_H
#include <iostream>
#include <string>

#include "Etat.h"

class E35 : public Etat
{
public:
	E35();
	virtual ~E35();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E35_H
