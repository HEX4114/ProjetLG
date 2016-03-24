#ifndef E17_H
#define E17_H
#include <iostream>
#include <string>

#include "Etat.h"

class E17 : public Etat
{
public:
	E17();
	virtual ~E17();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E17_H
