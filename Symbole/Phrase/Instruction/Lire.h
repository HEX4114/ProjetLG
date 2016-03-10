#ifndef LIRE_H
#define LIRE_H


#include "Instruction.h"
#include "../../Expression/Variable.h"

class Lire :
	public Instruction
{
public:
	Lire();
	~Lire();

	void setVariableAChanger(Variable variable) { variableAChanger = variable; };

	void afficher();
	void executer();

private:
	Variable variableAChanger;

};

#endif // LIRE_H
