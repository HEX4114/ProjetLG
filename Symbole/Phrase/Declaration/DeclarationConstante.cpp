#include <iostream>

#include "DeclarationConstante.h"


DeclarationConstante::DeclarationConstante() : Declaration()
{
}

DeclarationConstante::~DeclarationConstante()
{
}

void DeclarationConstante::afficher()
{
	std::cout << "CONST " << this->constanteADeclarer.getName() << " = " << this->constanteADeclarer.getValeur() << ";" << std::endl;
}

void DeclarationConstante::executer()
{
}
