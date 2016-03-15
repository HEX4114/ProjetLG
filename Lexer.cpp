#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctype.h>
#include "Lexer.h"
#include "Symbole/Symbole.h"

using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::getline;


using namespace std;

int Lexer::next = -1;

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

    // Notice how you can loop through a string just like a vector<char>
    for(size_t i = 0; i < example.size(); ++i)
    {
        char c = example[i];

        switch(c)
        {
        case ' ':
        case '\t':
        case '\n':
            //std::cout << "WHITESPACE " << std::endl;
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
            break;
        default:
            word += c;
        }
    }
}

Symbole Lexer::getNext()
{
    next++;
	Symbole* toReturn;
    if(getSymbole(next).compare("const")==0)
    {
        std::cout << "CONST" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(CONST);
        return *toReturn;
    }
    else if(getSymbole(next).compare("var")==0)
    {
        std::cout << "VAR" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(VAR);
        return *toReturn;
    }
	else if(getSymbole(next).compare("ecrire") == 0)
    {
        std::cout << "ECRIRE" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(ECRIRE);
        return *toReturn;
    }
	else if (getSymbole(next).compare("lire") == 0)
	{
		std::cout << "LIRE" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(LIRE);
		return *toReturn;
	}
	else if (getSymbole(next).compare(";") == 0)
	{
		std::cout << "PVG" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(PVG);
		return *toReturn;
	}
	else if (getSymbole(next).compare(",") == 0)
	{
		std::cout << "VG" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(VG);
		return *toReturn;
	}
	else if (getSymbole(next).compare("=") == 0)
	{
		std::cout << "EG" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(EG);
		return *toReturn;
	}
	else if (getSymbole(next).compare("(") == 0)
	{
		std::cout << "PARG" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(PARG);
		return *toReturn;
	}
	else if (getSymbole(next).compare(")") == 0)
	{
		std::cout << "PARD" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(PARD);
		return *toReturn;
	}
	else if (getSymbole(next).compare(":=") == 0)
	{
		std::cout << "AF" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(AF);
		return *toReturn;
	}
	else if (getSymbole(next).compare("+") == 0)
	{
		std::cout << "PLUS" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(PLUS);
		return *toReturn;
	}
	else if (getSymbole(next).at(0) == '-')
	{
		toReturn = new Symbole();
		if (getSymbole(next - 1).compare("=") != 0)
		{
			toReturn->setType(MOINS);
			std::cout << "MOINS" << std::endl;
			if (getSymbole(next).size() != 1)
			{
				string idOrNumber = getSymbole(next).erase(0, 1);
				std::vector<string>::iterator it = symboles.begin();
				symboles.insert(it + next + 1, idOrNumber);
			}
		}
		else
		{
			if (getSymbole(next).size() != 1)
			{
				if (isdigit(getSymbole(next).at(1)))
				{
					std::cout << "NB" << std::endl;
					toReturn->setType(NB);
				}
				else
				{
					std::cout << "MOINS" << std::endl;
					toReturn->setType(MOINS);
					string id = getSymbole(next).erase(0, 1);
					std::vector<string>::iterator it = symboles.begin();
					symboles.insert(it + next + 1, id);
				}
			}
			else
			{
				std::cout << "MOINS" << std::endl;
				toReturn->setType(MOINS);
			}
		}
		return *toReturn;
	}
	else if (getSymbole(next).compare("*") == 0)
	{
		std::cout << "MULT" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(MULT);
		return *toReturn;
	}
	else if (getSymbole(next).compare("/") == 0)
	{
		std::cout << "DIV" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(DIV);
		return *toReturn;
	}
	else if (isdigit(getSymbole(next).at(0)))
	{
		std::cout << "NB" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(NB);
		return *toReturn;
	}
	else
	{
		std::cout << "ID" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(ID);
		return *toReturn;
	}
};
