#ifndef EXPRESSIONSOUSTRAIRE_H
#define EXPRESSIONSOUSTRAIRE_H

#include "ExpressionBinaire.h"

class ExpressionSoustraire : public ExpressionBinaire
{
    public:
        ExpressionSoustraire();
        virtual ~ExpressionSoustraire();

		double evaluer();
    protected:
    private:
};

#endif // EXPRESSIONSOUSTRAIRE_H
