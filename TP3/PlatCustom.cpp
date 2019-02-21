#include "PlatCustom.h"


PlatCustom::PlatCustom(string nom, double prix , double cout,int nbIngredients ): Plat(nom, prix, cout), nbIngredients_(nbIngredients){

    supplement_ = calculerSupplement();
    type_ = Custom;

}

int PlatCustom::getNbIngredients() const{
    return nbIngredients_;
}

double PlatCustom::getSupplement() const{
    return supplement_;
}

void PlatCustom::setNbIngredients( int nbIngredients){
    nbIngredients_ = nbIngredients;
}

double PlatCustom::calculerSupplement() const{
    return (FRAIS_CUSTOMISATION * nbIngredients_);
}

ostream& operator<<(ostream& os, const PlatCustom& plat){
    os << plat << " contient" << plat.nbIngredients_ << "pour un supplement de: " << plat.supplement_ << "$ "  << endl;
	return os;
}
