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
	return e1->evaluer() * e2->evaluer();
}

std::string ExpressionMultiplier::getName()
{
	std::string valeurAAfficher;
	if (parG)
	{
		valeurAAfficher = "(" + e1->getName() + "*" + e2->getName();
	}
	else
	{
		valeurAAfficher = e1->getName() + "*" + e2->getName();
	}

	if (parD) { valeurAAfficher += ")"; }
	return valeurAAfficher;
}

bool ExpressionMultiplier::expressionDeclare()
{
	return ExpressionBinaire::expressionDeclare();
}

bool ExpressionMultiplier::expressionConnue()
{
	return ExpressionBinaire::expressionConnue();
}
