#include "ExpressionAdditionner.h"

ExpressionAdditionner::ExpressionAdditionner(Expression* exp1, Expression * exp2) : ExpressionBinaire(exp1, exp2)
{

}

ExpressionAdditionner::~ExpressionAdditionner()
{
    //dtor
}

double ExpressionAdditionner::evaluer()
{
	return (e1->evaluer() + e2->evaluer());
}

std::string ExpressionAdditionner::getName()
{
    std::string valeurAAfficher = e1->getName() + "+" + e2->getName();
    return valeurAAfficher;
}
