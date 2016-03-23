#ifndef EXPRESSIONDIVISER_H
#define EXPRESSIONDIVISER_H

#include <string>
#include "ExpressionBinaire.h"

class ExpressionDiviser : public ExpressionBinaire
{
    public:
        ExpressionDiviser(Expression * exp1, Expression * exp2);
        virtual ~ExpressionDiviser();

		double evaluer();
		bool expressionDeclare();
		bool expressionConnue();
		std::string getName();
    protected:
    private:
};

#endif // EXPRESSIONDIVISER_H
