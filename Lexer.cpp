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
    if(getSymbole(next).compare("const")==0)
    {
        std::cout << "CONST" << std::endl;
        return *new DeclarationConstante();
    }
    else if(getSymbole(next).compare("var")==0)
    {
        std::cout << "VAR" << std::endl;
        return *new DeclarationVariable();
    }
    else
    {
        std::cout << "AUTRE" << std::endl;
        return *new Symbole();
    }
};
