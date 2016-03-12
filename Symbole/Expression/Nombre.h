#ifndef NOMBRE_H
#define NOMBRE_H

#include <string>

#include "Expression.h"

class Nombre : public Expression
{
    public:
		Nombre();
        Nombre(double v);
        virtual ~Nombre();

        double virtual evaluer();

		double getValeur() { return valeur; };


    protected:
    private:
        double valeur;
};

#endif // NOMBRE_H
