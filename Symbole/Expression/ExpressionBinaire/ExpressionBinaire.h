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
		virtual void setUtilise();
		void setParentheses(bool parG, bool parD) { this->parG = parG; this->parD = parD; };

    protected:
		Expression* e1;
		Expression* e2;
		
		bool parG;
		bool parD;

    private:
};

#endif // EXPRESSIONBINAIRE_H
