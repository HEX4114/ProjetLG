#ifndef NOMBRE_H
#define NOMBRE_H

#include <string>

#include "Expression.h"

class Nombre : public Expression
{
    public:
		Nombre();
        Nombre(double v, std::string id);
        virtual ~Nombre();

        double virtual evaluer();

		double getValeur() { return valeur; };
		std::string getIdentifiant() { return identifiant; };


    protected:
    private:
        double valeur;
		std::string identifiant;
};

#endif // NOMBRE_H
