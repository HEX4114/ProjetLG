#include "ExpressionBinaire.h"

ExpressionBinaire::ExpressionBinaire(Expression * exp1, Expression * exp2) : Expression()
{
    e1 = exp1;
    e2 = exp2;
	parG = false;
	parD = false;
}

ExpressionBinaire::~ExpressionBinaire()
{
    //dtor
}

bool ExpressionBinaire::expressionDeclare()
{
	return e1->expressionDeclare() && e2->expressionDeclare();
}

bool ExpressionBinaire::expressionConnue()
{
	return e1->expressionConnue() && e2->expressionConnue();
}