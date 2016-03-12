#ifndef DECLARATION_CONSTANTE_H
#define DECLARATION_CONSTANTE_H

#include "Declaration.h"
#include "../../Expression/Constante.h"

class DeclarationConstante :
	public Declaration
{
public:
	DeclarationConstante();
	virtual ~DeclarationConstante();

	void setConstanteADeclarer(Constante constante) { constanteADeclarer = constante; };

	void afficher();
	void executer();

private:
	Constante constanteADeclarer;

};

#endif // DECLARATION_CONSTANTE_H

