#ifndef EXPRESSIONSOUSTRAIRE_H
#define EXPRESSIONSOUSTRAIRE_H

#include <string>
#include "ExpressionBinaire.h"

class ExpressionSoustraire : public ExpressionBinaire
{
    public:
        ExpressionSoustraire(Expression* exp1, Expression * exp2);
        virtual ~ExpressionSoustraire();

		double evaluer();
		bool expressionDeclare();
		bool expressionConnue();
		void setUtilise();
		std::string getName();
    protected:
    private:
};

#endif // EXPRESSIONSOUSTRAIRE_H
