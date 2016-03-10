#include "Variable.h"

Variable::Variable() : Expression()
{
    //ctor
}

Variable::Variable(double v, std::string id) : Expression()
{
	this->valeur = v;
	this->identifiant = id;
}

Variable::~Variable()
{
    //dtor
}

double Variable::evaluer()
{
    return this->valeur;
}
