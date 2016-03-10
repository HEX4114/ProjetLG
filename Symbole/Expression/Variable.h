#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

#include "Expression.h"

class Variable : public Expression
{
    public:
        Variable();
		Variable(double v, std::string id);
        virtual ~Variable();
        double virtual evaluer();

		double getValeur(){ return valeur; };
		std::string getIdentifiant() { return identifiant; };

    protected:
    private:
        std::string identifiant;
        double valeur;
};

#endif // VARIABLE_H
