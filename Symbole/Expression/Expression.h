#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include "../Symbole.h"

class Expression : public Symbole
{
    public:
        Expression();
        virtual ~Expression();
        virtual double evaluer()=0;
		virtual bool expressionDeclare() = 0;
		virtual bool expressionConnue() = 0;
        virtual std::string getName()=0;
    protected:
    private:
};

#endif // EXPRESSION_H
