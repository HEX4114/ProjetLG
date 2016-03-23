#include <sstream>
#include "Variable.h"
#include "../../Automate.h"
#include "../Programme/StatutIdentifiant.h"

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

bool Variable::expressionDeclare()
{
	if (automate->getStatutIdParIdentifiant(identifiant) != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Variable::expressionConnue()
{
	if (automate->getStatutIdParIdentifiant(identifiant)->isValeurConnue())
	{
		return true;
	}
	else
	{
		return false;
	}
}
