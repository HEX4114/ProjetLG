#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "Lexer.h"
using std::cout;
using std::cin;
using std::endl;

using std::vector;
#include <unordered_set>
using std::string;
using std::getline;


using namespace std;

#include "Symbole\Expression\ExpressionBinaire\ExpressionAdditionner.h"
#include "Symbole\Expression\ExpressionBinaire\ExpressionSoustraire.h"
#include "Symbole\Expression\ExpressionBinaire\ExpressionDiviser.h"
#include "Symbole\Expression\ExpressionBinaire\ExpressionMultiplier.h"
#include "Symbole\Symbole.h"
#include "Symbole\Expression\Nombre.h"
#include "Symbole\Programme\Programme.h"



int main(int argc, char* argv[])
{
	if (argc < 2)
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
	cout << endl;
	
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


	/*Test du tableau statique*/
	StatutIdentifiant v1("v1", true, false);
	StatutIdentifiant v2("v2", true, false);
	StatutIdentifiant v3("v3", true, false);
	StatutIdentifiant c1("c1", false, false);
	c1.setValeur(1);
	StatutIdentifiant c2("c2", false, false);
	c2.setValeur(2);
	StatutIdentifiant c3("c3", false, false);
	c3.setValeur(3);

	Programme programme;
	programme.addStatutIdentifiant(v1);
	bool a = programme.addStatutIdentifiant(v1);
	programme.addStatutIdentifiant(v2);
	programme.addStatutIdentifiant(v3);
	programme.addStatutIdentifiant(c1);
	programme.addStatutIdentifiant(c2);
	programme.addStatutIdentifiant(c3);
	programme.afficherTableauStatut();
	programme.majStatutIdentifiant(c1);
	programme.afficherTableauStatut();


    system("pause");

     return 0;
}
