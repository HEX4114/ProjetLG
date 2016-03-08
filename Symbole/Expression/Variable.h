#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Expression.h"

using namespace std;

class Variable : public Expression
{
    public:
        Variable();
        virtual ~Variable();
        double virtual evaluer();
    protected:
    private:
        string identifiant;
        double valeur;
};

#endif // VARIABLE_H
