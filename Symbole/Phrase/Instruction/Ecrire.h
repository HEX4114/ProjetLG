#ifndef ECRIRE_H
#define ECRIRE_H

#include "Instruction.h"

class Ecrire :
	public Instruction
{
public:
	Ecrire();
	~Ecrire();

	void afficher();
	void executer();
};

#endif // ECRIRE_H

