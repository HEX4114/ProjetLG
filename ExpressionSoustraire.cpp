#include "include/ExpressionSoustraire.h"

ExpressionSoustraire::ExpressionSoustraire()
{
    //ctor
}

ExpressionSoustraire::~ExpressionSoustraire()
{
    //dtor
}

double ExpressionSoustraire::evaluer()
{
	return e1.evaluer() - e2.evaluer();;
}
