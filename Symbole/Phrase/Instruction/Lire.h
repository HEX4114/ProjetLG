#ifndef LIRE_H
#define LIRE_H


#include "Instruction.h"
class Lire :
	public Instruction
{
public:
	Lire();
	~Lire();

	void afficher();
	void executer();
};

#endif // LIRE_H
