#ifndef EXPRESSIONMULTIPLIER_H
#define EXPRESSIONMULTIPLIER_H

#include "ExpressionBinaire.h"

class ExpressionMultiplier : public ExpressionBinaire
{
    public:
        ExpressionMultiplier();
        virtual ~ExpressionMultiplier();

		double evaluer();
    protected:
    private:
};

#endif // EXPRESSIONMULTIPLIER_H
