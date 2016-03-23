#ifndef EXPRESSIONMULTIPLIER_H
#define EXPRESSIONMULTIPLIER_H

#include <string>
#include "ExpressionBinaire.h"

class ExpressionMultiplier : public ExpressionBinaire
{
    public:
        ExpressionMultiplier(Expression* exp1, Expression * exp2);
        virtual ~ExpressionMultiplier();

		double evaluer();
		bool expressionDeclare();
		bool expressionConnue();
		std::string getName();
    protected:
    private:
};

#endif // EXPRESSIONMULTIPLIER_H
