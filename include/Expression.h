#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Symbole.h"

class Expression : public Symbole
{
    public:
        Expression();
        virtual ~Expression();
        double virtual evaluer()=0;
    protected:
    private:
};

#endif // EXPRESSION_H
