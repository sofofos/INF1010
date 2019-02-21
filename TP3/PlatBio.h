/*
* Titre : PlatBio.h - Travail Pratique #2
* Date : 11 F�vrier 2019
* Auteur : Fatou S. MOUNZEO
*/



#include <string>
#include <iostream>
#include "Plat.h"

using namespace std;

class PlatBio: public Plat {
public:
	// constructeurs
	PlatBio(string nom = "inconnu", double prix = 0, double cout = 0,double ecotaxe = 0);

	//getters
	double getEcoTaxe() const;

	//setters
	void setEcoTaxe(double ecoTaxe);

	//methodes en plus

	friend ostream& operator<<(ostream& os, const PlatBio& plat); ///

private:
	double ecoTaxe_;
};
