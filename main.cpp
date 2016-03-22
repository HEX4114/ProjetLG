#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::getline;

using namespace std;

#include "Lexer.h"
#include "Symbole\Expression\ExpressionBinaire\ExpressionAdditionner.h"
#include "Symbole\Expression\ExpressionBinaire\ExpressionSoustraire.h"
#include "Symbole\Expression\ExpressionBinaire\ExpressionDiviser.h"
#include "Symbole\Expression\ExpressionBinaire\ExpressionMultiplier.h"
#include "Symbole\Symbole.h"
#include "Symbole\Expression\Nombre.h"
#include "Symbole\Phrase\Instruction\Ecrire.h"
#include "Symbole\Phrase\Instruction\Lire.h"
#include "Automate.h"
#include "Symbole/Phrase/Declaration/DeclarationConstante.h"
#include "Symbole/Phrase/Declaration/DeclarationVariable.h"

int main(int argc, char* argv[])

{
	/*Test Automate*/
	//1.Recup fichier a l'aide de l'outil en ligne de commande
	string fileName = "src/test.txt";
	//2. lancement de l'automate
	Automate* automate = new Automate();
	automate->lecture(fileName);
	
	
	/*if (argc < 2)
	{
		cerr << "Usage: ProjetGL sourceFile [options]" << endl;
		system("pause");
		return 0;
	}

	unordered_set<string> options;
	string opt[] = { "-a","-e","-o","-p" };
	unordered_set<string> authorisedOptions (opt, opt + 4);
	for (int i = 2; i < argc; i++)
	{
		string s(argv[i], 2);
		if (authorisedOptions.find(s) != authorisedOptions.end())
		{
			options.insert(s);
		}
		else {
			cerr << "Valid options are : -a, -e, -o and -p" << endl;
			system("pause");
			return 0;
		}
	}
	cout << "Options : ";
	for (auto it = options.begin(); it != options.end(); ++it)
		cout << " " << *it;
	cout << endl;*/

    /*cout << "Hello world!" << endl;


	char* sourceFile = argv[1];
	string fileName = string(sourceFile);



    Lexer* lex = new Lexer();
    string names = lex->lecture(fileName);
    lex->parseToSymbols(names);

    while(lex->hasNext()) {
        Symbole sym = lex->getNext();
    }*/


    /**Tests des Expressions**/
    /*Nombre * n1 = new Nombre(1);
    Nombre * n2 = new Nombre(5);
    ExpressionAdditionner * Exp1 = new ExpressionAdditionner(n1, n2);
    ExpressionSoustraire * Exp2 = new ExpressionSoustraire(n1, n2);
    ExpressionDiviser * Exp3 = new ExpressionDiviser(n1, n2);
    ExpressionMultiplier * Exp4 = new ExpressionMultiplier(n1, n2);
    cout<< Exp1->evaluer()<<endl<< Exp2->evaluer() <<endl<< Exp3->evaluer() <<endl<< Exp4->evaluer() <<endl;*/
    /**-------------------**/

	
    /**Tests d'Ecrire afficher() et executer()**/
    /*Ecrire * ExpAAff1 = new Ecrire();
    Ecrire * ExpAAff2 = new Ecrire();
    Nombre * n1 = new Nombre(1);
    Nombre * n2 = new Nombre(5);
    Nombre * n = new Nombre(10);
    ExpressionAdditionner * Exp1 = new ExpressionAdditionner(n1, n2);
    //ExpressionSoustraire * Exp1 = new ExpressionSoustraire(n1, n2);
    //ExpressionDiviser * Exp1 = new ExpressionDiviser(n1, n2);
    //ExpressionMultiplier * Exp1 = new ExpressionMultiplier(n1, n2);
    ExpAAff1->setVariableAAfficher(n);
    ExpAAff2->setVariableAAfficher(Exp1);
    ExpAAff1->afficher();
    ExpAAff1->executer();
    ExpAAff2->afficher();
    ExpAAff2->executer();*/
    /**-------------------**/

    /**Tests d'Affectation afficher() et executer()**/
    /*Variable * v1 = new Variable(10,"z");
    Nombre * n2 = new Nombre(5);
    Nombre * n1 = new Nombre(10);
    ExpressionAdditionner * Exp1 = new ExpressionAdditionner(n1, n2);
    //ExpressionSoustraire * Exp1 = new ExpressionSoustraire(n1, n2);
    //ExpressionDiviser * Exp1 = new ExpressionDiviser(n1, n2);
    //ExpressionMultiplier * Exp1 = new ExpressionMultiplier(n1, n2);
    Affectation * ExpAff = new Affectation(v1, Exp1);
    ExpAff->afficher();
    ExpAff->executer();
    std::cout<<"=> z="<<v1->getValeur()<<std::endl;*/
    /**-------------------**/

    /**Tests de Lire afficher() et executer()**/
    /*Variable * v = new Variable(10,"z");
    //ExpressionSoustraire * Exp1 = new ExpressionSoustraire(n1, n2);
    //ExpressionDiviser * Exp1 = new ExpressionDiviser(n1, n2);
    //ExpressionMultiplier * Exp1 = new ExpressionMultiplier(n1, n2);
    Lire * valALire = new Lire(v);
    valALire->afficher();
    valALire->executer();
    std::cout<<"=> z="<<v->getValeur()<<std::endl;*/
    /**-------------------**/

	/**Test du tableau statique**/
	/*StatutIdentifiant v1("v1", true, false);
<<<<<<< HEAD
=======

>>>>>>> feature/automate
	StatutIdentifiant v2("v2", true, false);
	StatutIdentifiant v3("v3", true, false);
	StatutIdentifiant c1("c1", false, false);
	c1.setValeur(1);
	StatutIdentifiant c2("c2", false, false);
	c2.setValeur(2);
	StatutIdentifiant c3("c3", false, false);
	c3.setValeur(3);

	Automate automate;
	automate.addStatutIdentifiant(v1);
	bool a = automate.addStatutIdentifiant(v1);
	automate.addStatutIdentifiant(v2);
	automate.addStatutIdentifiant(v3);
	automate.addStatutIdentifiant(c1);
	automate.addStatutIdentifiant(c2);
	automate.addStatutIdentifiant(c3);
	automate.afficherTableauStatut();
	automate.majStatutIdentifiant(c1);
	automate.afficherTableauStatut();*/
    /**-------------------**/

    /**Test de executer() de Declaration**/
    /*Automate * aut = new Automate();
    Constante * c = new Constante(10,"c");
    Variable * v = new Variable();
    v->setID("v");
    DeclarationConstante * d1 = new DeclarationConstante();
    d1->setConstanteADeclarer(*c);
    d1->setAutomate(aut);
    DeclarationVariable * d2 = new DeclarationVariable();
    d2->setVariableADeclarer(*v);
    d2->setAutomate(aut);
    d1->executer();
    d2->executer();
    aut->afficherTableauStatut();*/
    /**-------------------**/


    system("pause");

     return 0;
}
