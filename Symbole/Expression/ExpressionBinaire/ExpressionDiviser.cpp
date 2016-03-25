#include "ExpressionDiviser.h"

ExpressionDiviser::ExpressionDiviser(Expression* exp1, Expression * exp2) : ExpressionBinaire(exp1, exp2)
{
    //ctor
}

ExpressionDiviser::~ExpressionDiviser()
{
    //dtor
}

double ExpressionDiviser::evaluer()
{
	return e1->evaluer() / e2->evaluer();
}

std::string ExpressionDiviser::getName()
{
	std::string valeurAAfficher;
	if (parG)
	{
		valeurAAfficher = "(" + e1->getName() + "/" + e2->getName();
	}
	else
	{
		valeurAAfficher = e1->getName() + "/" + e2->getName();
	}

	if (parD) { valeurAAfficher += ")"; }
    return valeurAAfficher;
}

bool ExpressionDiviser::expressionDeclare()
{
	return ExpressionBinaire::expressionDeclare();
}

bool ExpressionDiviser::expressionConnue()
{
	return ExpressionBinaire::expressionConnue();
}

void ExpressionDiviser::setUtilise()
{
	ExpressionBinaire::setUtilise();
}