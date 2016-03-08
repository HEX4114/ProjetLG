#include "include/ExpressionBinaire.h"

ExpressionBinaire::ExpressionBinaire(Expression * exp1, Expression * exp2) : Expression()
{
    e1 = exp1;
    e2 = exp2;
}

ExpressionBinaire::~ExpressionBinaire()
{
    //dtor
}

double ExpressionBinaire::evaluer()
{
    return 0;
}
