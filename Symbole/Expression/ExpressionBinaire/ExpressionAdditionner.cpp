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
	std::string valeurAAfficher;
	if (parG)
	{
		valeurAAfficher = "(" + e1->getName() + "+" + e2->getName();
	}
	else
	{
		valeurAAfficher = e1->getName() + "+" + e2->getName();
	}

	if (parD) { valeurAAfficher += ")"; }
    return valeurAAfficher;
}

bool ExpressionAdditionner::expressionDeclare()
{
	return ExpressionBinaire::expressionDeclare();
}

bool ExpressionAdditionner::expressionConnue()
{
	return ExpressionBinaire::expressionConnue();
}