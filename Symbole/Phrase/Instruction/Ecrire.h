#ifndef ECRIRE_H
#define ECRIRE_H

#include "Instruction.h"
#include "../../Expression/Expression.h"


class Ecrire :
	public Instruction
{
public:
	Ecrire();
	~Ecrire();

	void setVariableAAfficher(Expression* expression) { expressionAAfficher = expression; };

	void afficher();
	void executer();
	void analyseStatique();

private:
	Expression* expressionAAfficher;

};

#endif // ECRIRE_H

