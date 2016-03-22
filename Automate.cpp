#include "Automate.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <typeinfo> 
#include "Lexer.h"
#include "Etat/E0.h"
#include "Symbole/Symbole.h"
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

	partieGaucheRegle.push_back(Symbole(D));
	partieGaucheRegle.push_back(Symbole(V));
	partieGaucheRegle.push_back(Symbole(V));
	partieGaucheRegle.push_back(Symbole(C));
	partieGaucheRegle.push_back(Symbole(C));
	partieGaucheRegle.push_back(Symbole(D));
	partieGaucheRegle.push_back(Symbole(D));
	partieGaucheRegle.push_back(Symbole(D));
	partieGaucheRegle.push_back(Symbole(I));
	partieGaucheRegle.push_back(Symbole(I));
	partieGaucheRegle.push_back(Symbole(I));
	partieGaucheRegle.push_back(Symbole(I));
	partieGaucheRegle.push_back(Symbole(E));
	partieGaucheRegle.push_back(Symbole(E));
	partieGaucheRegle.push_back(Symbole(T));
	partieGaucheRegle.push_back(Symbole(T));
	partieGaucheRegle.push_back(Symbole(F));
	partieGaucheRegle.push_back(Symbole(F));
	partieGaucheRegle.push_back(Symbole(F));

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
		pileEtats.top()->transition(*this, *symbole);
		cout << typeid(*pileEtats.top()).name() << endl;
		symbole = lex->getSymbole();
	}

	//4. appeler les options
}

void Automate::empilerEtat(Etat* etat)
{
	pileEtats.push(etat);
}

void Automate::empilerSymbole(Symbole symbole)
{
	pileSymboles.push(symbole);
}

void Automate::reduction(Regle regle)
{
	int nbPop = reglesReduction.at(regle);

	for (int i=0; i<nbPop; i++) pileEtats.pop();
	
	Symbole partG = partieGaucheRegle[regle];
	cout << "reduction de " << regle << endl;
	pileEtats.top()->transition(*this, partG);
}

void Automate::decalageTerminal(Symbole symbole, Etat* etat)
{
	//Empiler symbole seulement si c'est un symbole terminal
	empilerSymbole(symbole);
	lex->goNext();
	cout << "decalage de " << symbole.getType() << endl;
	empilerEtat(etat);
}

void Automate::decalageNonTerminal(Symbole symbole, Etat* etat)
{
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
