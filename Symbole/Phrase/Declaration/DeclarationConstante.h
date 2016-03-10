#ifndef DECLARATION_CONSTANTE_H
#define DECLARATION_CONSTANTE_H

#include "Declaration.h"
class DeclarationConstante :
	public Declaration
{
public:
	DeclarationConstante();
	virtual ~DeclarationConstante();

	void afficher();
	void executer();
};

#endif // DECLARATION_CONSTANTE_H

