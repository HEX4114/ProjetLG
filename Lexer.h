#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>
#include "Symbole/Symbole.h"
using std::string;

#include "Symbole\Phrase\Declaration\DeclarationConstante.h"
#include "Symbole\Phrase\Declaration\DeclarationVariable.h"
#include "Symbole\Phrase\Instruction\Affectation.h"

class Lexer
{
    public:
        Lexer();
        virtual ~Lexer();
        string lecture(string& fileName);
        void parseToSymbols(string& examples);
        void goNext();
        Symbole* getSymbole();
        bool hasNext() {
            if((int) symboles.size()>next) {
                return true;
            } else {
                return false;
            }
        }
        void addSymbole(string& word)
		{
			symboles.push_back(word);
		}
		string getSymbole(int next)
		{
			return symboles.at(next);
		}

    protected:

    private:
        //bool test_regex_search(const std::string& input);
        std::vector<string> symboles;
        static int next;
};

#endif // LEXER_H
