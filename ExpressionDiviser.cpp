#include "include/ExpressionDiviser.h"

ExpressionDiviser::ExpressionDiviser()
{
    //ctor
}

ExpressionDiviser::~ExpressionDiviser()
{
    //dtor
}

double ExpressionDiviser::evaluer()
{
	return e1->evaluer() / e2->evaluer();;
}
