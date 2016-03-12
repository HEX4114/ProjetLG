#ifndef STATUT_IDENTIFIANT_H
#define STATUT_IDENTIFIANT_H

#include <string>

class StatutIdentifiant
{
public:
	StatutIdentifiant();
	virtual ~StatutIdentifiant();

	void afficher();

private:
	std::string id;
	bool modifiable;
	double valeur;
	bool utilise;
	bool valeurConnue;

};

#endif // STATUT_IDENTIFIANT_H

