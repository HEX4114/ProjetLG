#include<iostream>
#include "Lire.h"


Lire::Lire() : Instruction()
{
}

Lire::Lire(Variable* v) : Instruction()
{
    variableAChanger = v;
}

Lire::~Lire()
{
}

void Lire::afficher()
{
    std::cout << "lire " << this->variableAChanger->getName() << ";" << std::endl;
}

void Lire::executer()
{
    double n;
    std::cout<<":";std::cin >>n;
    variableAChanger->setValeur(n);
}
