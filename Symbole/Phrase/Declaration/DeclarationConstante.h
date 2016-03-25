#ifndef DECLARATION_CONSTANTE_H
#define DECLARATION_CONSTANTE_H

#include "Declaration.h"
#include "../../Expression/Variable.h"

class DeclarationConstante :
	public Declaration
{
public:
	DeclarationConstante();
	virtual ~DeclarationConstante();

	Variable* getConstanteADeclarer(){ return constanteADeclarer; };
	void setConstanteADeclarer(Variable* constante) { constanteADeclarer = constante; };

	void afficher();
	void executer();
	void analyseStatique();

private:
	Variable* constanteADeclarer;
};

#endif // DECLARATION_CONSTANTE_H

