#include <iostream>
#include <fstream>
#include <regex>
#include "Lexer.h"
#include "Symbole\Expression\Nombre.h"
#include "Symbole\Expression\Variable.h"

using namespace std;

int Lexer::next = 0;
vector<string> Lexer::symboles;

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

    ifstream t(fileName.c_str());
    if (t.is_open())
    {
        t.seekg(0, ios::end);
        size_t size = t.tellg();
        string lines(size, ' ');
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
    string word;

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
                cout << word << endl;
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
                cout << word << endl;
                addSymbole(word);
                word.clear();
            }
            word += c;
            cout << word << endl;
            addSymbole(word);
            word.clear();
            break;
        case '-':
            if(!word.empty())
            {
                cout << word << endl;
                addSymbole(word);
                word.clear();
                word += c;
                cout << word << endl;
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
                cout << word << endl;
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
                    cout << word << endl;
                    addSymbole(word);
                    word.clear();
                }
                else
                {
                    cout << word << endl;
                    addSymbole(word);
                    word.clear();
                    word += c;
                    cout << word << endl;
                    addSymbole(word);
                    word.clear();
                }
            }
            else
            {
                word += c;
                cout << word << endl;
                addSymbole(word);
                word.clear();
            }
            break;
        default:
            word += c;
        }
    }
    word += '$';
    cout << word << endl;
    addSymbole(word);
}

bool testRegex(const string& input, const TypeSymbole& reg)
{
    regex rgx;
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

    smatch match;

    if (regex_match(input.begin(), input.end(), match, rgx))
    {
        return true;
    }
    else
        return false;
}

bool Lexer::hasNext()
{
    if((int) symboles.size()>next)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Lexer::addSymbole(string& word)
{
    symboles.push_back(word);
}

string Lexer::getSymbole(int next)
{
    return symboles.at(next);
}

void Lexer::goNext()
{
    next++;
}

Symbole* Lexer::getSymbole()
{
    if(getSymbole(next).compare("const")==0)
    {
        cout << "CONST" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(CONST);
        return toReturn;
    }
    else if(getSymbole(next).compare("var")==0)
    {
        cout << "VAR" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(VAR);
        return toReturn;
    }
    else if(getSymbole(next).compare("ecrire") == 0)
    {
        cout << "ECRIRE" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(ECRIRE);
        return toReturn;
    }
    else if (getSymbole(next).compare("lire") == 0)
    {
        cout << "LIRE" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(LIRE);
        return toReturn;
    }
    else if (getSymbole(next).compare(";") == 0)
    {
        cout << "PVG" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(PVG);
        return toReturn;
    }
    else if (getSymbole(next).compare(",") == 0)
    {
        cout << "VG" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(VG);
        return toReturn;
    }
    else if (getSymbole(next).compare("=") == 0)
    {
        cout << "EG" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(EG);
        return toReturn;
    }
    else if (getSymbole(next).compare("(") == 0)
    {
        cout << "PARG" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(PARG);
        return toReturn;
    }
    else if (getSymbole(next).compare(")") == 0)
    {
        cout << "PARD" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(PARD);
        return toReturn;
    }
    else if (getSymbole(next).compare(":=") == 0)
    {
        cout << "AF" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(AF);
        return toReturn;
    }
    else if (getSymbole(next).compare("+") == 0)
    {
        cout << "PLUS" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(PLUS);
        return toReturn;
    }
    else if (getSymbole(next).compare("-") == 0)
    {
        cout << "MOINS" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(MOINS);
        return toReturn;
    }
    else if (getSymbole(next).compare("*") == 0)
    {
        cout << "MULT" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(MULT);
        return toReturn;
    }
    else if (getSymbole(next).compare("/") == 0)
    {
        cout << "DIV" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(DIV);
        return toReturn;
    }
    else if (testRegex(getSymbole(next), NB))
    {
        cout << "NB" << endl;
        Nombre* toReturn = new Nombre(stoi(getSymbole(next)));
        toReturn->setType(NB);
        return toReturn;
    }
    else if(testRegex(getSymbole(next), ID))
    {
        cout << "ID" << endl;
        Variable* toReturn = new Variable();
        toReturn->setID(getSymbole(next));
        toReturn->setType(ID);
        return toReturn;
    }
    else if(getSymbole(next).at(0) == '-')
    {
        if(next-1>0)
        {
            if((getSymbole(next-1).compare("=") == 0 || getSymbole(next-1).compare(":=") == 0) && testRegex(getSymbole(next).substr(1), ID))
            {
                cout << "ID" << endl;
                Variable* toReturn = new Variable();
                toReturn->setID(getSymbole(next));
                toReturn->setType(ID);
                return toReturn;
            }
            else
            {
                cout << "ERROR " << getSymbole(next) << endl;
                Symbole* toReturn = new Symbole();
                toReturn->setType(ERR);
                return toReturn;
            }
        }
        else
        {
            cout << "ID" << endl;
            Variable* toReturn = new Variable();
            toReturn->setID(getSymbole(next));
            toReturn->setType(ID);
            return toReturn;
        }
    }
    else if (getSymbole(next).compare("$") == 0)
    {
        cout << "DOL" << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(DOL);
        return toReturn;
    }
    else
    {
        cout << "ERROR " << getSymbole(next) << endl;
        Symbole* toReturn = new Symbole();
        toReturn->setType(ERR);
        return toReturn;
    }
    //next++;
    return NULL;
};
