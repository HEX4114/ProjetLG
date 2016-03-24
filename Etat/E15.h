#ifndef E15_H
#define E15_H
#include <iostream>
#include <string>

#include "Etat.h"

class E15 : public Etat
{
public:
	E15();
	virtual ~E15();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E15_H
