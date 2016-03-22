#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <string>
#include "Expression.h"
class Constante :
	public Expression
{
public:
	Constante();
	Constante(double v, std::string id);
	virtual ~Constante();


	double virtual evaluer();
	std::string virtual getName(){ return identifiant; };
	double getValeur(){ return valeur; };
private:
	std::string identifiant;
	double valeur;
};

#endif // CONSTANTE_H

