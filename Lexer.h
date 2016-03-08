#ifndef LEXER_H
#define LEXER_H
#include <string>
using std::string;


class Lexer
{
    public:
        Lexer();
        virtual ~Lexer();
        string lecture(const std::string& fileName);
        string parseToSymbols(const std::string& examples);
        //Symbole getNext();
    protected:

    private:
};

#endif // LEXER_H
