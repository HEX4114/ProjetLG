#include "include/ExpressionMultiplier.h"

ExpressionMultiplier::ExpressionMultiplier()
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
