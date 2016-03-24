#ifndef E25_H
#define E25_H
#include <iostream>
#include <string>

#include "Etat.h"

class E25 : public Etat
{
public:
	E25();
	virtual ~E25();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E25_H
