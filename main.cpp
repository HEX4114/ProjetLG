#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "include/Lexer.h"
using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::getline;


using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    string fileName = "C:/Users/Sylwia/Documents/ProjetLG/test.txt";
    Lexer* lex = new Lexer();
    string names = lex->lecture(fileName);
    string examples = lex->parseToSymbols(names);

    //print array
    //int len = names.length();
    //for(int i = 0; i < len; i++)
    //{
    //     cout<<names[i];
    //}


     return 0;
}
