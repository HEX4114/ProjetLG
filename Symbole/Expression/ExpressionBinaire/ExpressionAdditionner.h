#ifndef EXPRESSIONADDITIONNER_H
#define EXPRESSIONADDITIONNER_H

#include <string>
#include "ExpressionBinaire.h"

class ExpressionAdditionner : public ExpressionBinaire
{
    public:
        ExpressionAdditionner(Expression * exp1, Expression * exp2);
        virtual ~ExpressionAdditionner();

		double evaluer();
		std::string getName();
    protected:
    private:
};

#endif // EXPRESSIONADDITIONNER_H
