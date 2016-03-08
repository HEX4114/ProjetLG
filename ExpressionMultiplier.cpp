#include "include/ExpressionMultiplier.h"

ExpressionMultiplier::ExpressionMultiplier(Expression* exp1, Expression * exp2) : ExpressionBinaire(exp1, exp2)
{
    //ctor
}

ExpressionMultiplier::~ExpressionMultiplier()
{
    //dtor
}

double ExpressionMultiplier::evaluer()
{
	return e1->evaluer() * e2->evaluer();;
}
