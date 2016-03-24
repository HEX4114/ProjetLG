#ifndef E16_H
#define E16_H
#include <iostream>
#include <string>

#include "Etat.h"

class E16 : public Etat
{
public:
	E16();
	virtual ~E16();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E16_H
