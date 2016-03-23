#ifndef EXPRESSIONBINAIRE_H
#define EXPRESSIONBINAIRE_H

#include "../Expression.h"

class ExpressionBinaire : public Expression
{
    public:
        ExpressionBinaire(Expression * exp1, Expression * exp2);
        virtual ~ExpressionBinaire();
        virtual double evaluer()=0;
		virtual bool expressionDeclare();
		virtual bool expressionConnue();
        virtual std::string getName()=0;
    protected:
		Expression* e1;
		Expression* e2;
    private:
};

#endif // EXPRESSIONBINAIRE_H
