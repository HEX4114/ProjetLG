#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "Lexer.h"
using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::getline;


using namespace std;

#include "Symbole\Expression\ExpressionBinaire\ExpressionAdditionner.h"
#include "Symbole\Expression\ExpressionBinaire\ExpressionSoustraire.h"
#include "Symbole\Expression\ExpressionBinaire\ExpressionDiviser.h"
#include "Symbole\Expression\ExpressionBinaire\ExpressionMultiplier.h"
#include "Symbole\Expression\Nombre.h"


int main()
{
    cout << "Hello world!" << endl;

    string fileName = "../sources/test.txt";

    Lexer* lex = new Lexer();
    string names = lex->lecture(fileName);
    string examples = lex->parseToSymbols(names);

    //print array
    //int len = names.length();
    //for(int i = 0; i < len; i++)
    //{
    //     cout<<names[i];
    //}



    /**Tests des Expressions**/
    /*Nombre * n1 = new Nombre(1);
    Nombre * n2 = new Nombre(5);
    ExpressionAdditionner * Exp1 = new ExpressionAdditionner(n1, n2);
    ExpressionSoustraire * Exp2 = new ExpressionSoustraire(n1, n2);
    ExpressionDiviser * Exp3 = new ExpressionDiviser(n1, n2);
    ExpressionMultiplier * Exp4 = new ExpressionMultiplier(n1, n2);
    cout<< Exp1->evaluer()<<endl<< Exp2->evaluer() <<endl<< Exp3->evaluer() <<endl<< Exp4->evaluer() <<endl;*/
    /**-------------------**/

    //system("pause");

     return 0;
}
