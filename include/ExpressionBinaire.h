#ifndef EXPRESSIONBINAIRE_H
#define EXPRESSIONBINAIRE_H

#include "Expression.h"

class ExpressionBinaire : public Expression
{
    public:
        ExpressionBinaire();
        virtual ~ExpressionBinaire();
        double virtual evaluer()=0;
    protected:
    private:
};

#endif // EXPRESSIONBINAIRE_H
