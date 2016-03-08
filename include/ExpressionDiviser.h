#ifndef EXPRESSIONDIVISER_H
#define EXPRESSIONDIVISER_H

#include "ExpressionBinaire.h"

class ExpressionDiviser : public ExpressionBinaire
{
    public:
        ExpressionDiviser(Expression * exp1, Expression * exp2);
        virtual ~ExpressionDiviser();

		double evaluer();
    protected:
    private:
};

#endif // EXPRESSIONDIVISER_H
