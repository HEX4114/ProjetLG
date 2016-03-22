#ifndef DECLARATION_VARIABLE_H
#define DECLARATION_VARIABLE_H

#include "Declaration.h"
#include "../../Expression/Variable.h"

class DeclarationVariable :
	public Declaration
{
public:
	DeclarationVariable();
	virtual ~DeclarationVariable();

	void afficher();
	void executer();

    void setVariableADeclarer(Variable variable) { variableADeclarer = variable; };

private:
	Variable variableADeclarer;
};

#endif // DECLARATION_VARIABLE_H
