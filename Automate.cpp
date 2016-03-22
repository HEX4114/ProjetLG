#include "Automate.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "Lexer.h"
#include "Etat/E0.h"
#include "Symbole\Symbole.h"
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
	//1. Creer Lexer
	Lexer* lex = new Lexer();
	string names = lex->lecture(fileName);
	lex->parseToSymbols(names);

	//2.Empiler E0
	pileEtats.push(new E0);
	
	//3. pour chaque symbole passer dans l'automate : transition etat
	lectureFinie = false;
	int taillePileSymbP = pileSymboles.size();
	int taillePileSymbC = pileSymboles.size();
	Symbole symbole = lex->getNext(); //premier symbole
	while(!lectureFinie) {
		taillePileSymbC = pileSymboles.size();
		if ((taillePileSymbC > taillePileSymbP) && lex->hasNext())
		{
			symbole = lex->getNext();
		}
		taillePileSymbP = pileSymboles.size();
		pileEtats.top()->transition(*this, symbole);
		cout << typeid(*pileEtats.top()).name() << endl;
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

bool Automate::estUnTerminal(Symbole symbole)
{
	for (int i = 0; i < partieGaucheRegle.size(); i++) 
	{
		if (partieGaucheRegle[i].getType() == symbole.getType()) 
		{
			return false;
		}
	}
	return true;
}