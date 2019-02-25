/***********************************************************************
* Titre : PlatBio.cpp - Travail Pratique #3
* Date : 11 Fevrier 2019
* Auteur :Fatou S. MOUNZEO
***********************************************************************
* Modidié par : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 24 Février 2019
************************************************************************/
#include "PlatBio.h"

using namespace std;

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe): Plat(nom, prix, cout){
    ecoTaxe_= ecotaxe;
    type_ = Bio;
}

double PlatBio::getEcoTaxe() const{
    return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe){
    ecoTaxe_ = ecoTaxe;
}

ostream& operator<<(ostream& os, const PlatBio& plat){
	os << static_cast<Plat>(plat) << "\tcomprend une taxe ecologique de : " << plat.ecoTaxe_ << "$." << endl;
	return os;
}
