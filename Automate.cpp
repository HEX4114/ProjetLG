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
	for (int i = 0; i<14; i++) {
		Symbole symbole = lex->getNext();
		pileEtats.top()->transition(*this, symbole);
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

void Automate::reduction(Regle regle, Symbole symbole)
{
	int nbPop = reglesReduction.at(regle);

	for (int i=0; i<nbPop; i++) pileEtats.pop();
	
	Symbole nextSymb = partieGaucheRegle[regle];
	pileEtats.top()->transition(*this, nextSymb);
}

void Automate::decalage(Symbole symbole, Etat* etat)
{
	empilerSymbole(symbole);
	empilerEtat(etat);
}
