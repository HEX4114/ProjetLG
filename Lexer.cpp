#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctype.h>
#include "Lexer.h"
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
		toReturn->setType(TypeSymbole::CONST);
        return *toReturn;
    }
    else if(getSymbole(next).compare("var")==0)
    {
        std::cout << "VAR" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::VAR);
        return *toReturn;
    }
	else if(getSymbole(next).compare("ecrire") == 0)
    {
        std::cout << "ECRIRE" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::ECRIRE);
        return *toReturn;
    }
	else if (getSymbole(next).compare("lire") == 0)
	{
		std::cout << "LIRE" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::LIRE);
		return *toReturn;
	}
	else if (getSymbole(next).compare(";") == 0)
	{
		std::cout << "PVG" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::PVG);
		return *toReturn;
	}
	else if (getSymbole(next).compare(",") == 0)
	{
		std::cout << "VG" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::VG);
		return *toReturn;
	}
	else if (getSymbole(next).compare("=") == 0)
	{
		std::cout << "EG" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::EG);
		return *toReturn;
	}
	else if (getSymbole(next).compare("(") == 0)
	{
		std::cout << "PARG" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::PARG);
		return *toReturn;
	}
	else if (getSymbole(next).compare(")") == 0)
	{
		std::cout << "PARD" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::PARD);
		return *toReturn;
	}
	else if (getSymbole(next).compare(":=") == 0)
	{
		std::cout << "AF" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::AF);
		return *toReturn;
	}
	else if (getSymbole(next).compare("+") == 0)
	{
		std::cout << "PLUS" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::PLUS);
		return *toReturn;
	}
	else if (getSymbole(next).at(0) == '-')
	{
		if (getSymbole(next).size() == 1)
		{
			std::cout << "MOINS" << std::endl;
			toReturn = new Symbole();
			toReturn->setType(TypeSymbole::MOINS);
			return *toReturn;
		}
		else
		{
			std::cout << "NB" << std::endl;
			toReturn = new Symbole();
			toReturn->setType(TypeSymbole::NB);
			return *toReturn;
		}
	}
	else if (getSymbole(next).compare("*") == 0)
	{
		std::cout << "MULT" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::MULT);
		return *toReturn;
	}
	else if (getSymbole(next).compare("/") == 0)
	{
		std::cout << "DIV" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::DIV);
		return *toReturn;
	}
	else if (isdigit(getSymbole(next).at(0)))
	{
		std::cout << "NB" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::NB);
		return *toReturn;
	}
	else
	{
		std::cout << "ID" << std::endl;
		toReturn = new Symbole();
		toReturn->setType(TypeSymbole::ID);
		return *toReturn;
	}
};
