#include "include/ExpressionAdditionner.h"

ExpressionAdditionner::ExpressionAdditionner()
{
    //ctor
}

ExpressionAdditionner::~ExpressionAdditionner()
{
    //dtor
}

double ExpressionAdditionner::evaluer()
{
	return e1->evaluer() + e2->evaluer();
}
