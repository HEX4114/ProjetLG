#include "ExpressionSoustraire.h"

ExpressionSoustraire::ExpressionSoustraire(Expression* exp1, Expression * exp2) : ExpressionBinaire(exp1, exp2)
{
    //ctor
}

ExpressionSoustraire::~ExpressionSoustraire()
{
    //dtor
}

double ExpressionSoustraire::evaluer()
{
	return e1->evaluer() - e2->evaluer();;
}

std::string ExpressionSoustraire::getName()
{
    std::string valeurAAfficher = e1->getName() + "-" + e2->getName();
    return valeurAAfficher;
}
