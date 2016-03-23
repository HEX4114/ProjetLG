#include "Automate.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <typeinfo> 
#include "Lexer.h"
#include "Etat/E0.h"
#include "Symbole/Symbole.h"

#include "Symbole/Phrase/Declaration/DeclarationConstante.h"
#include "Symbole/Phrase/Declaration/DeclarationVariable.h"
#include "Symbole/Phrase/Instruction/Affectation.h"
#include "Symbole/Phrase/Instruction/Lire.h"
#include "Symbole/Phrase/Instruction/Ecrire.h"
#include "Symbole/Expression/Nombre.h"
#include "Symbole/Expression/ExpressionBinaire/ExpressionAdditionner.h"
#include "Symbole/Expression/ExpressionBinaire/ExpressionDiviser.h"
#include "Symbole/Expression/ExpressionBinaire/ExpressionMultiplier.h"
#include "Symbole/Expression/ExpressionBinaire/ExpressionSoustraire.h"

using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::getline;


using namespace std;

Automate::Automate()
{
    //ctor
	reglesReduction.push_back(2);
	reglesReduction.push_back(3);
	reglesReduction.push_back(0);
	reglesReduction.push_back(5);
	reglesReduction.push_back(0);
	reglesReduction.push_back(5);
	reglesReduction.push_back(7);
	reglesReduction.push_back(0);
	reglesReduction.push_back(4);
	reglesReduction.push_back(4);
	reglesReduction.push_back(5);
	reglesReduction.push_back(0);
	reglesReduction.push_back(3);
	reglesReduction.push_back(1);
	reglesReduction.push_back(3);
	reglesReduction.push_back(1);
	reglesReduction.push_back(3);
	reglesReduction.push_back(1);
	reglesReduction.push_back(1);

	partieGaucheRegle.push_back(new Symbole(D));
	partieGaucheRegle.push_back(new Symbole(V));
	partieGaucheRegle.push_back(new Symbole(V));
	partieGaucheRegle.push_back(new Symbole(C));
	partieGaucheRegle.push_back(new Symbole(C));
	partieGaucheRegle.push_back(new Symbole(D));
	partieGaucheRegle.push_back(new Symbole(D));
	partieGaucheRegle.push_back(new Symbole(D));
	partieGaucheRegle.push_back(new Symbole(I));
	partieGaucheRegle.push_back(new Symbole(I));
	partieGaucheRegle.push_back(new Symbole(I));
	partieGaucheRegle.push_back(new Symbole(I));
	partieGaucheRegle.push_back(new Symbole(E));
	partieGaucheRegle.push_back(new Symbole(E));
	partieGaucheRegle.push_back(new Symbole(T));
	partieGaucheRegle.push_back(new Symbole(T));
	partieGaucheRegle.push_back(new Symbole(F));
	partieGaucheRegle.push_back(new Symbole(F));
	partieGaucheRegle.push_back(new Symbole(F));

	lex = new Lexer();
}

Automate::~Automate()
{
	// TODO
	/*
	for (int i = 0; i < pileEtats.size; i++)
	{
		delete(pileEtats.pop);
	}
	*/
}

void Automate::lecture(std::string fileName)
{
	//1. Initialiser Lexer
	string names = lex->lecture(fileName);
	lex->parseToSymbols(names);

	//2.Empiler E0
	pileEtats.push(new E0);
	
	//3. boucle transitions
	lectureFinie = false;
	Symbole *symbole = lex->getSymbole(); //premier symbole
	while(!lectureFinie) {
		try 
		{
			pileEtats.top()->transition(*this, symbole);
		}
		catch (std::pair<int, string> p)
		{
			cout << p.second << endl;
			if(p.first == 1) lectureFinie = true;
		}
		
		cout << typeid(*pileEtats.top()).name() << endl;
		symbole = lex->getSymbole();
	}
	Programme prog = concatenerSymboles();
	prog.afficherProgramme();
	//system("pause");
	//4. appeler les options
}

void Automate::empilerEtat(Etat* etat)
{
	pileEtats.push(etat);
}

void Automate::empilerSymbole(Symbole* symbole)
{
	pileSymboles.push(symbole);
}

void Automate::reduction(Regle regle) throw(std::pair<int, string>)
{
	int nbPop = reglesReduction.at(regle);

	for (int i=0; i<nbPop; i++) pileEtats.pop();
	
	Symbole *partG = partieGaucheRegle[regle];
	cout << "reduction de " << regle << endl;
	pileEtats.top()->transition(*this, partG);
}

void Automate::decalageTerminal(Symbole* symbole, Etat* etat)
{
	//Empiler symbole seulement si c'est un symbole terminal
	empilerSymbole(symbole);
	lex->goNext();
	cout << "decalage de " << symbole->getType() << endl;
	empilerEtat(etat);
}

void Automate::decalageNonTerminal(Symbole* symbole, Etat* etat)
{
	empilerEtat(etat);
}

void Automate::decalageAnticipe(Symbole* symbole, Etat* etat)
{
	//Empiler symbole dans le cas oï¿½ le compilo anticipe une erreure.
	empilerSymbole(symbole);
	cout << "decalage de " << symbole->getType() << endl;
	empilerEtat(etat);
}

void Automate::accepter()
{
	lectureFinie = true;
	cout << "c'est fini !!" << endl;
}

void Automate::afficherTableauStatut()
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		it->afficher();
	}
}

bool Automate::addStatutIdentifiant(StatutIdentifiant s)
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		if (it->getId().compare(s.getId()) == 0)
		{
			return false;
		}
	}
	tableauStatut.push_back(s);
	return true;
}

bool Automate::majStatutIdentifiant(StatutIdentifiant s)
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		if (it->getId().compare(s.getId()) == 0)
		{
			(*it) = s;
			return true;
		}
	}
	return false;
}

StatutIdentifiant* Automate::getStatutIdParIdentifiant(std::string identifiant)
{
	for (std::vector<StatutIdentifiant>::iterator it = tableauStatut.begin(); it != tableauStatut.end(); ++it)
	{
		if (it->getId().compare(identifiant) == 0)
		{
			return &(*it);
		}
	}

	return NULL;
}

Programme Automate::concatenerSymboles()
{
	std::list<Symbole*> listeSymboles = viderPileSymbole();
	std::list<std::list<Symbole*>> listePhrase;
	Programme programme;
	std::list<Symbole*> listeTemp;
	for (std::list<Symbole*>::iterator it = listeSymboles.begin(); it != listeSymboles.end(); it++)
	{
		listeTemp.push_back(*it);
		if ((*it)->getType() == PVG)
		{
			listePhrase.push_back(listeTemp);
			listeTemp.clear();
		}
		else if ((*it)->getType() == VG)
		{
			listeTemp.pop_back();
			listeTemp.push_back(new Symbole(PVG));

			++it;
			if ((*listeTemp.begin())->getType() == CONST)
			{
				listeSymboles.insert(it, new Symbole(CONST));
			}
			else if ((*listeTemp.begin())->getType() == VAR)
			{
				listeSymboles.insert(it,new Symbole(VAR));
			}
			--it;
			--it;

			listePhrase.push_back(listeTemp);
			listeTemp.clear();
		}
	}
	return creerObjetsPhrase(listePhrase);
	
}

std::list<Symbole*> Automate::viderPileSymbole()
{
	std::list<Symbole*> listeSymbole;
	while (!pileSymboles.empty())
	{
		listeSymbole.push_front(pileSymboles.top());
		pileSymboles.pop();
	}
	return listeSymbole;
}

void Automate::remplirPileSymbole(std::list<Symbole*> liste)
{
	for (std::list<Symbole*>::iterator it = liste.begin(); it != liste.end(); ++it)
	{
		pileSymboles.push(*it);
	}
}

std::string Automate::getIDValue(Symbole* symbole)
{
	Variable* var = dynamic_cast<Variable*>( symbole);
	return var->getName();
}

double Automate::getNumberValue(Symbole* symbole)
{
	Nombre* nb = dynamic_cast<Nombre*>(symbole);
	return 1;
}

Programme Automate::creerObjetsPhrase(std::list<std::list<Symbole*>> listeSymbole)
{
	Programme aRetourner;
	std::list<Phrase*> listePhrase;

	for (std::list<std::list<Symbole*>>::iterator it = listeSymbole.begin(); it != listeSymbole.end(); ++it)
	{
		std::list<Symbole*>::iterator itSymbole = it->begin();
		if ((*itSymbole)->getType() == VAR)
		{
			DeclarationVariable* declaration = new DeclarationVariable;
			Variable var; ++itSymbole;
			var.setID(getIDValue(*itSymbole));
			declaration->setAutomate(this);
			declaration->setVariableADeclarer(var);
			listePhrase.push_back(declaration);
		}
		else if ((*itSymbole)->getType() == CONST)
		{
			DeclarationConstante* declaration = new DeclarationConstante;
			Variable var; ++itSymbole;
			var.setID(getIDValue(*itSymbole)); ++itSymbole; ++itSymbole;
			var.setValeur(getNumberValue(*itSymbole));
			declaration->setAutomate(this);
			declaration->setConstanteADeclarer(var);
			listePhrase.push_back(declaration);
		}
		else if ((*itSymbole)->getType() == ECRIRE)
		{
			Ecrire* ecrire = new Ecrire; ++itSymbole;
			Expression* expression = parseExpression(itSymbole);
			ecrire->setAutomate(this);
			ecrire->setVariableAAfficher(expression);
			listePhrase.push_back(ecrire);
		}
		else if ((*itSymbole)->getType() == LIRE)
		{
			Lire* instruction;
			Variable *var = new Variable; ++itSymbole;
			var->setID(getIDValue(*itSymbole));
			instruction->setAutomate(this);
			instruction->setVariableAChanger(var);
			listePhrase.push_back(instruction);

		}
		else if ((*itSymbole)->getType() == ID)
		{
			Affectation* affecter = new Affectation;
			Variable * variable = new Variable; variable->setID(getIDValue(*itSymbole));
			affecter->setPartieGauche(variable); ++itSymbole; ++itSymbole;
			affecter->setAutomate(this);
			Expression* expression = parseExpression(itSymbole);
			affecter->setPartieDroite(expression);
			listePhrase.push_back(affecter);
		}
	}
	aRetourner.setListePhrase(listePhrase);
	return aRetourner;
}

//Implémentation de la notation polonaise inversée

Expression* Automate::parseExpression(std::list<Symbole*>::iterator it)
{
	std::stack<Symbole*> operateurs;
	std::stack<Symbole*> sortie;
	while ((*it)->getType() != PVG)
	{
		TypeSymbole type = (*it)->getType();
		if (type == ID || type == NB)
		{
			sortie.push(*it);
		}
		else if (type == PARG)
		{
			operateurs.push(*it);
		}
		else if (type == PLUS || type == MOINS || type == MULT || type == DIV)
		{
			if (operateurs.empty())
			{
				operateurs.push(*it);
			}
			else if(operateurs.top()->getType() == PARG)
			{
				operateurs.push(*it);
			}
			else if (estPrioritaire(type, operateurs.top()->getType()))
			{
				operateurs.push(*it);
			}
			else
			{
				Symbole * symbolePrioritaire = operateurs.top();
				operateurs.pop();
				Expression *partieDroite = dynamic_cast<Expression*>(sortie.top()); sortie.pop();
				Expression *partieGauche;
				if (!sortie.empty())
				{
					partieGauche = dynamic_cast<Expression*>(sortie.top()); sortie.pop();
				}
				else
				{
					partieGauche = new Nombre(0);
				}
				operateurs.push(*it);
				sortie.push(creerExpressionBinaire(symbolePrioritaire->getType(),partieGauche, partieDroite));

			}
		}
		else if (type == PARD)
		{
			while (operateurs.top()->getType() != PARG)
			{
				Symbole * operateur = operateurs.top();
				operateurs.pop();
				sortie.push(operateur);
			}
			operateurs.pop();
		}
		it++;
	}

	while (!operateurs.empty())
	{
		
		Symbole * operateur = operateurs.top();
		Expression *partieDroite = dynamic_cast<Expression*>(sortie.top()); sortie.pop();
		Expression *partieGauche;
		if (!sortie.empty())
		{
			partieGauche = dynamic_cast<Expression*>(sortie.top()); sortie.pop();
		}
		else
		{
			partieGauche = new Nombre(0);
		}
		sortie.push(creerExpressionBinaire(operateur->getType(), partieGauche, partieDroite));
		operateurs.pop();
	}
	return dynamic_cast<Expression*>(sortie.top());

}

bool Automate::estPrioritaire(TypeSymbole t1, TypeSymbole t2)
{
	if (t1 == MULT || t1 == DIV)
	{
		if (t2 == PLUS || t2 == MOINS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

ExpressionBinaire* Automate::creerExpressionBinaire(TypeSymbole t1, Expression* e1, Expression* e2)
{
	ExpressionBinaire* expression;
	if (t1 == PLUS)
	{
		expression = new ExpressionAdditionner(e1, e2);
	}
	else if(t1 == MOINS)
	{
		expression = new ExpressionSoustraire(e1, e2);
	}
	else if (t1 == MULT)
	{
		expression = new ExpressionMultiplier(e1, e2);
	}
	else if (t1 == DIV)
	{
		expression = new ExpressionDiviser(e1, e2);
	}
	return expression;
}