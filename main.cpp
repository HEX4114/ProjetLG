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
	

	char* sourceFile = argv[1];
	string fileName = string(sourceFile);

    Lexer* lex = new Lexer();
    string names = lex->lecture(fileName);
    lex->parseToSymbols(names);

    for(int i=0; i<14; i++) {
        Symbole sym = lex->getNext();
    }
	


    /**Tests des Expressions**/
    /*Nombre * n1 = new Nombre(1);
    Nombre * n2 = new Nombre(5);
    ExpressionAdditionner * Exp1 = new ExpressionAdditionner(n1, n2);
    ExpressionSoustraire * Exp2 = new ExpressionSoustraire(n1, n2);
    ExpressionDiviser * Exp3 = new ExpressionDiviser(n1, n2);
    ExpressionMultiplier * Exp4 = new ExpressionMultiplier(n1, n2);
    cout<< Exp1->evaluer()<<endl<< Exp2->evaluer() <<endl<< Exp3->evaluer() <<endl<< Exp4->evaluer() <<endl;*/
    /**-------------------**/

    system("pause");

     return 0;
}
