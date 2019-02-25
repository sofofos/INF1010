/*********************************************************************
* Titre : PlatCustom.cpp - Travail Pratique #3
* Date : 11 Fevrier 2019
* Auteur :Fatou S. MOUNZEO
***********************************************************************
* Modidié par : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 24 Février 2019
***********************************************************************/

#include "PlatCustom.h"
#include "Plat.h"


PlatCustom::PlatCustom(string nom, double prix, double cout, int nbIngredients): Plat(nom,prix,cout){

    nbIngredients_ = nbIngredients;
    type_ = Custom;
    supplement_ = calculerSupplement();
}

int PlatCustom::getNbIngredients() const{
    return nbIngredients_;
}

double PlatCustom::getSupplement()const {
    return supplement_;
}

void PlatCustom::setNbIngredients(int nbIngredients){
    nbIngredients_ = nbIngredients;
}


double PlatCustom::calculerSupplement()const{
    return (FRAIS_CUSTOMISATION * nbIngredients_);
}

ostream& operator<<(ostream& os, const PlatCustom& plat){
	os << static_cast<Plat>(plat) << "\tcontient " << plat.nbIngredients_ << " elements modifies pour un supplement total de : "
		<< plat.supplement_ << "$." << endl;

	return os;
 }
