#ifndef EXPRESSIONBINAIRE_H
#define EXPRESSIONBINAIRE_H

#include "Expression.h"

class ExpressionBinaire : public Expression
{
    public:
        ExpressionBinaire();
        virtual ~ExpressionBinaire();

		virtual double evaluer();
    protected:
    private:
};

#endif // EXPRESSIONBINAIRE_H
