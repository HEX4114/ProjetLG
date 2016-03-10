#ifndef AFFECTATION_H
#define AFFECTATION_H


#include "Instruction.h"

class Affectation :
	public Instruction
{
public:
	Affectation();
	~Affectation();

	void afficher();
	void executer();

};

#endif //AFFECTION_H
