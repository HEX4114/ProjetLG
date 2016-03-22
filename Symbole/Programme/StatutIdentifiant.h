#ifndef STATUT_IDENTIFIANT_H
#define STATUT_IDENTIFIANT_H

#include <string>

class StatutIdentifiant
{
public:
	StatutIdentifiant();
	StatutIdentifiant(std::string ID, bool Modifiable, bool Utilise);
	virtual ~StatutIdentifiant();

	void afficher();

	std::string getId(){ return id; };
	void setId(std::string i){ id = i; };

	bool isModifiable(){ return modifiable; };
	void setModifiable(bool m){ modifiable = m; };

	double getValeur(){ return valeur; };
	void setValeur(double v){ valeur = v; valeurConnue = true; };

	bool isUtilise(){ return utilise; };
	void setUtilise(bool u){ utilise = u; };

	bool isValeurConnue(){ return valeurConnue; };
	void setValeurConnue(bool v){ valeurConnue = v; };

private:
	std::string id;
	bool modifiable;
	double valeur;
	bool utilise;
	bool valeurConnue;

};

#endif // STATUT_IDENTIFIANT_H

