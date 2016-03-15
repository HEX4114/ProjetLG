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
#include "Symbole\Symbole.h"
#include "Symbole\Expression\Nombre.h"
#include "Symbole\Phrase\Instruction\Ecrire.h"
#include "Symbole\Phrase\Instruction\Lire.h"


int main()
{
    /*cout << "Hello world!" << endl;

    string fileName = "src/test.txt";

    Lexer* lex = new Lexer();
    string names = lex->lecture(fileName);
    lex->parseToSymbols(names);

    for(int i=0; i<14; i++) {
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

    system("pause");

     return 0;
}
