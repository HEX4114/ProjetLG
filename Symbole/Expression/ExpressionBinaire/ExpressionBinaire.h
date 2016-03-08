#ifndef EXPRESSIONBINAIRE_H
#define EXPRESSIONBINAIRE_H

#include "../Expression.h"

class ExpressionBinaire : public Expression
{
    public:
        ExpressionBinaire(Expression * exp1, Expression * exp2);
        virtual ~ExpressionBinaire();
        double virtual evaluer()=0;
    protected:
		Expression* e1;
		Expression* e2;
    private:
};

#endif // EXPRESSIONBINAIRE_H