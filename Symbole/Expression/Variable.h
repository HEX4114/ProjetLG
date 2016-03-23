#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

#include "Expression.h"

class Automate;

class Variable : public Expression
{
    public:
        Variable();
		Variable(double v, std::string id);
        virtual ~Variable();


        double virtual evaluer();
		bool virtual expressionDeclare();
		bool virtual expressionConnue();


        std::string virtual getName(){ return identifiant; };
		void setID(std::string id){ identifiant = id; };
		double getValeur(){ return valeur; };
		void setValeur(double v){ valeur = v; };
		void setAutomate(Automate* automate){ this->automate = automate; };

    protected:
    private:
        std::string identifiant;
		Automate * automate;
        double valeur;
};

#endif // VARIABLE_H
