#ifndef E26_H
#define E26_H
#include <iostream>
#include <string>

#include "Etat.h"

class E26 : public Etat
{
public:
	E26();
	virtual ~E26();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E26_H
