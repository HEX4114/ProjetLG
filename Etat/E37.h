#ifndef E37_H
#define E37_H
#include <iostream>
#include <string>

#include "Etat.h"

class E37 : public Etat
{
public:
	E37();
	virtual ~E37();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E37_H
