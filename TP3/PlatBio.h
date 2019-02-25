/***********************************************************************
* Titre : PlatBio.h - Travail Pratique #3
* Date : 11 Fevrier 2019
* Auteur :Fatou S. MOUNZEO
***********************************************************************
* Modidié par : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 24 Février 2019
************************************************************************/

#ifndef PLATBIO_H
#define PLATBIO_H


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
#endif