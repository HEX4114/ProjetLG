#ifndef E9_H
#define E9_H
#include <iostream>
#include <string>

#include "Etat.h"

class E9 : public Etat
{
public:
	E9();
	virtual ~E9();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E9_H
