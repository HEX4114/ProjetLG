#ifndef ETAT_H
#define ETAT_H
#include <iostream>
#include <string>

#include "../Symbole/Symbole.h"
#include "E0.h"
#include "E1.h"
#include "E2.h"
#include "E3.h"
#include "E4.h"
#include "E5.h"
#include "E6.h"
#include "E7.h"
#include "E8.h"
#include "E9.h"
#include "E10.h"
#include "E11.h"
#include "E12.h"
#include "E13.h"
#include "E14.h"
#include "E15.h"
#include "E16.h"
#include "E17.h"
#include "E18.h"
#include "E19.h"
#include "E20.h"
#include "E21.h"
#include "E22.h"
#include "E23.h"
#include "E24.h"
#include "E25.h"
#include "E26.h"
#include "E27.h"
#include "E28.h"
#include "E29.h"
#include "E30.h"
#include "E31.h"
#include "E32.h"
#include "E33.h"
#include "E34.h"
#include "E35.h"
#include "E36.h"
#include "E37.h"
#include "E38.h"
#include "E39.h"
#include "E40.h"


class Automate;

class Etat
{
    public:
        Etat();
        virtual ~Etat();
		virtual bool transition(Automate automate, Symbole symbole) = 0;
    protected:
        std::string name;
    private:
};

#endif // ETAT_H
