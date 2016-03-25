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
	StatutIdentifiant* statut = automate->getStatutIdParIdentifiant(identifiant);
    return statut->getValeur();
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

void Variable::setUtilise()
{
	StatutIdentifiant* statut = automate->getStatutIdParIdentifiant(identifiant);
	if (statut != NULL)
	{
		automate->getStatutIdParIdentifiant(identifiant)->setUtilise(true);
	}
}
