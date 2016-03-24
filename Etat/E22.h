#ifndef E22_H
#define E22_H
#include <iostream>
#include <string>

#include "Etat.h"

class E22 : public Etat
{
public:
	E22();
	virtual ~E22();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E22_H
