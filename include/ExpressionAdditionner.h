#ifndef EXPRESSIONADDITIONNER_H
#define EXPRESSIONADDITIONNER_H

#include "ExpressionBinaire.h"

class ExpressionAdditionner : public ExpressionBinaire
{
    public:
        ExpressionAdditionner();
        virtual ~ExpressionAdditionner();

		double evaluer();
    protected:
    private:
};

#endif // EXPRESSIONADDITIONNER_H
