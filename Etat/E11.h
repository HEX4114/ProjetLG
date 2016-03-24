#ifndef E11_H
#define E11_H
#include <iostream>
#include <string>

#include "Etat.h"

class E11 : public Etat
{
public:
	E11();
	virtual ~E11();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E11_H
