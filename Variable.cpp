#include "include/Variable.h"

Variable::Variable() : Expression()
{
    //ctor
}

Variable::~Variable()
{
    //dtor
}

double Variable::evaluer()
{
    return this->valeur;
}
