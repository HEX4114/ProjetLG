#ifndef EXPRESSIONADDITIONNER_H
#define EXPRESSIONADDITIONNER_H

#include "ExpressionBinaire.h"

class ExpressionAdditionner : public ExpressionBinaire
{
    public:
        ExpressionAdditionner(Expression * exp1, Expression * exp2);
        virtual ~ExpressionAdditionner();

		double evaluer();
    protected:
    private:
};

#endif // EXPRESSIONADDITIONNER_H
