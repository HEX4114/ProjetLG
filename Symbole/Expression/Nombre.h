#ifndef NOMBRE_H
#define NOMBRE_H

#include "Expression.h"

class Nombre : public Expression
{
    public:
        Nombre(double v);
        virtual ~Nombre();
        double virtual evaluer();
    protected:
    private:
        double valeur;
};

#endif // NOMBRE_H
