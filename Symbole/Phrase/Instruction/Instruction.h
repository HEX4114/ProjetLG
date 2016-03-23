#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../Phrase.h"

class Instruction :
	public Phrase
{
public:
	Instruction();

	virtual void afficher() = 0;
	virtual void executer() = 0;
	virtual void analyseStatique() = 0;
	virtual ~Instruction();
};

#endif // INSTRUCTION_H
