#ifndef E38_H
#define E38_H
#include <iostream>
#include <string>

#include "Etat.h"

class E38 : public Etat
{
public:
	E38();
	virtual ~E38();
	virtual bool transition(Automate& automate, Symbole* symbole) throw(std::pair<int, std::string>);
protected:
	std::string name;
private:
};

#endif // E38_H
