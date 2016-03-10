#ifndef DECLARATION_CONSTANTE_H
#define DECLARATION_CONSTANTE_H

#include "Declaration.h"
#include "../../Expression/Nombre.h"

class DeclarationConstante :
	public Declaration
{
public:
	DeclarationConstante();
	virtual ~DeclarationConstante();

	void setConstanteADeclarer(Nombre constante) { constanteADeclarer = constante; };

	void afficher();
	void executer();

private:
	Nombre constanteADeclarer;

};

#endif // DECLARATION_CONSTANTE_H

