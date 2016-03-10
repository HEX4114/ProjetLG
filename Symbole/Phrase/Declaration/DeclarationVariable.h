#ifndef DECLARATION_VARIABLE_H
#define DECLARATION_VARIABLE_H

#include "Declaration.h"
class DeclarationVariable :
	public Declaration
{
public:
	DeclarationVariable();
	virtual ~DeclarationVariable();

	void afficher();
	void executer();

};

#endif // DECLARATION_VARIABLE_H
