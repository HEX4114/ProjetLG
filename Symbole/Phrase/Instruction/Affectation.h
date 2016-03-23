#ifndef AFFECTATION_H
#define AFFECTATION_H


#include "Instruction.h"
#include "../../Expression/Expression.h"
#include "../../Expression/Variable.h"

class Affectation :
	public Instruction
{
public:
	Affectation();
	Affectation(Variable* v, Expression* e);
	~Affectation();

	void setPartieGauche(Variable* partieG) { partieGauche = partieG; };
	void setPartieDroite(Expression* partieD) { partieDroite = partieD; };

	void afficher();
	void executer();
	void analyseStatique();

private:
	Variable* partieGauche;
	Expression* partieDroite;

};

#endif //AFFECTION_H
