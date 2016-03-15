#include "ExpressionMultiplier.h"

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

std::string ExpressionMultiplier::getName()
{
    std::string valeurAAfficher = e1->getName() + "*" + e2->getName();
    return valeurAAfficher;
}
