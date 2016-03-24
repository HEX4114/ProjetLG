#ifndef E33_H
#define E33_H
#include <iostream>
#include <string>

#include "Etat.h"

class E33 : public Etat
{
public:
	E33();
	virtual ~E33();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E33_H
