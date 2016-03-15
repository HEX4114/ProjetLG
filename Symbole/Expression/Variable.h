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
        std::string virtual getName(){ return identifiant; };
		double getValeur(){ return valeur; };
		void setValeur(double v){ valeur = v; };

    protected:
    private:
        std::string identifiant;
        double valeur;
};

#endif // VARIABLE_H
