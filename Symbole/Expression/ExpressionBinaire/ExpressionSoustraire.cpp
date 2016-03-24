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
	std::string valeurAAfficher;
	if (parG)
	{
		valeurAAfficher = "(" + e1->getName() + "-" + e2->getName();
	}
	else
	{
		valeurAAfficher = e1->getName() + "-" + e2->getName();
	}

	if (parD) { valeurAAfficher += ")"; }
	return valeurAAfficher;
}

bool ExpressionSoustraire::expressionDeclare()
{
	return ExpressionBinaire::expressionDeclare();
}

bool ExpressionSoustraire::expressionConnue()
{
	return ExpressionBinaire::expressionConnue();
}

