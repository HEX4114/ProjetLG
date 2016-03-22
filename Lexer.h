#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>
#include "Symbole/Symbole.h"

#include "Symbole/Phrase/Declaration/DeclarationConstante.h"
#include "Symbole/Phrase/Declaration/DeclarationVariable.h"
#include "Symbole/Phrase/Instruction/Affectation.h"

using std::string;
using std::vector;


class Lexer
{
    public:
        Lexer();
        virtual ~Lexer();
        string lecture(string& fileName);
        void parseToSymbols(string& examples);
        bool hasNext();
        Symbole* getSymbole();
        void goNext();

    protected:

    private:
        static vector<string> symboles;
        static int next;
        void addSymbole(string& word);
		string getSymbole(int next);
};

#endif // LEXER_H
