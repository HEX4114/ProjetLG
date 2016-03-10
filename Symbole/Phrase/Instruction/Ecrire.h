#ifndef ECRIRE_H
#define ECRIRE_H

#include "Instruction.h"
#include "../../Expression/Variable.h"

class Ecrire :
	public Instruction
{
public:
	Ecrire();
	~Ecrire();

	void setVariableAChanger(Variable variable) { variableAChanger = variable; };

	void afficher();
	void executer();

private:
	Variable variableAChanger;

};

#endif // ECRIRE_H

