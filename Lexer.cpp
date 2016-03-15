#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <regex>
#include <ctype.h>
#include "Lexer.h"
#include "Symbole/Symbole.h"

using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::getline;


using namespace std;

int Lexer::next = 0;

Lexer::Lexer()
{
    //ctor
}

Lexer::~Lexer()
{
    //dtor
}

string Lexer::lecture(string& fileName)
{

    std::ifstream t(fileName.c_str());
    if (t.is_open())
    {
        t.seekg(0, std::ios::end);
        size_t size = t.tellg();
        std::string lines(size, ' ');
        t.seekg(0);
        t.read(&lines[0], size);
        return lines;
    }
    else cout << "Unable to open file";
    exit(-1);
    return NULL;
}

void Lexer::parseToSymbols(string& example)
{
    std::string word;

    for(size_t i = 0; i < example.size(); ++i)
    {
        char c = example[i];

        switch(c)
        {
        case ' ':
        case '\t':
        case '\n':
            if(!word.empty())
            {
                std::cout << word << std::endl;
                addSymbole(word);
                word.clear();
            }
            break;
        case '+':
        case '*':
        case '/':
        case ';':
        case ',':
        case '(':
        case ')':
            if(!word.empty())
            {
                std::cout << word << std::endl;
                addSymbole(word);
                word.clear();
            }
            word += c;
            std::cout << word << std::endl;
            addSymbole(word);
            word.clear();
            break;
        case '-':
            if(!word.empty())
            {
                std::cout << word << std::endl;
                addSymbole(word);
                word.clear();
                word += c;
                std::cout << word << std::endl;
                addSymbole(word);
                word.clear();
            }
            else
            {
                word += c;
            }
            break;
        case ':':
            if(!word.empty())
            {
                std::cout << word << std::endl;
                addSymbole(word);
                word.clear();
            }
            word += c;
            break;
        case '=':
            if(!word.empty())
            {
                if(word.compare(":")==0)
                {
                    word += c;
                    std::cout << word << std::endl;
                    addSymbole(word);
                    word.clear();
                }
                else
                {
                    std::cout << word << std::endl;
                    addSymbole(word);
                    word.clear();
                    word += c;
                    std::cout << word << std::endl;
                    addSymbole(word);
                    word.clear();
                }
            }
            else
            {
                word += c;
                std::cout << word << std::endl;
                addSymbole(word);
                word.clear();
            }
            break;
        default:
            word += c;
        }
    }
}

bool testRegex(const std::string& input, const TypeSymbole& reg)
{
    std::regex rgx;
    if(reg == NB)
    {
        rgx = "[-]*[0-9]+";
    }
    else if(reg == ID)
    {
        rgx = "[a-zA-Z][a-zA-Z0-9]*";
    }
    else
    {
        rgx = "";
    }

    std::smatch match;

    if (std::regex_match(input.begin(), input.end(), match, rgx))
    {
        return true;
    }
    else
        return false;
}

Symbole Lexer::getNext()
{
    Symbole* toReturn;
    if(getSymbole(next).compare("const")==0)
    {
        std::cout << "CONST" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(CONST);
        //return *toReturn;
    }
    else if(getSymbole(next).compare("var")==0)
    {
        std::cout << "VAR" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(VAR);
        //return *toReturn;
    }
    else if(getSymbole(next).compare("ecrire") == 0)
    {
        std::cout << "ECRIRE" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(ECRIRE);
        //return *toReturn;
    }
    else if (getSymbole(next).compare("lire") == 0)
    {
        std::cout << "LIRE" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(LIRE);
        //return *toReturn;
    }
    else if (getSymbole(next).compare(";") == 0)
    {
        std::cout << "PVG" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(PVG);
        //return *toReturn;
    }
    else if (getSymbole(next).compare(",") == 0)
    {
        std::cout << "VG" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(VG);
        //return *toReturn;
    }
    else if (getSymbole(next).compare("=") == 0)
    {
        std::cout << "EG" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(EG);
        //return *toReturn;
    }
    else if (getSymbole(next).compare("(") == 0)
    {
        std::cout << "PARG" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(PARG);
        //return *toReturn;
    }
    else if (getSymbole(next).compare(")") == 0)
    {
        std::cout << "PARD" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(PARD);
        //return *toReturn;
    }
    else if (getSymbole(next).compare(":=") == 0)
    {
        std::cout << "AF" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(AF);
        //return *toReturn;
    }
    else if (getSymbole(next).compare("+") == 0)
    {
        std::cout << "PLUS" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(PLUS);
        //return *toReturn;
    }
    else if (getSymbole(next).compare("-") == 0)
    {
        std::cout << "MOINS" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(MOINS);
        //return *toReturn;
    }
    else if (getSymbole(next).compare("*") == 0)
    {
        std::cout << "MULT" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(MULT);
        //return *toReturn;
    }
    else if (getSymbole(next).compare("/") == 0)
    {
        std::cout << "DIV" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(DIV);
        //return *toReturn;
    }
    else if (testRegex(getSymbole(next), NB))
    {
        std::cout << "NB" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(NB);
        //return *toReturn;
    }
    else if(testRegex(getSymbole(next), ID))
    {
        std::cout << "ID" << std::endl;
        toReturn = new Symbole();
        toReturn->setType(ID);
        //return *toReturn;
    }
    else if(getSymbole(next).at(0) == '-')
    {
        if(next-1>0)
        {
            if((getSymbole(next-1).compare("=") == 0 || getSymbole(next-1).compare(":=") == 0) && testRegex(getSymbole(next).substr(1), ID))
            {
                std::cout << "ID" << std::endl;
                toReturn = new Symbole();
                toReturn->setType(ID);
                //return *toReturn;
            }
            else
            {
                std::cout << "ERROR " << getSymbole(next) << std::endl;
                toReturn = new Symbole();
                toReturn->setType(ERR);
                //return *toReturn;
            }
        }
        else
        {
            std::cout << "ID" << std::endl;
            toReturn = new Symbole();
            toReturn->setType(ID);
            //return *toReturn;
        }
    }
    else
    {
        std::cout << "ERROR " << getSymbole(next) << std::endl;
        toReturn = new Symbole();
        toReturn->setType(ERR);
        //return *toReturn;
    }
    next++;
    return *toReturn;
};
