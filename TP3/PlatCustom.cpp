#include "PlatCustom.h"

PlatCustom::PlatCustom(string nom, double prix , double cout,int nbIngredients ): Plat(nom, prix, cout, nbIngredients){}

int PlatCustom::getNbIngredients() const{
    return nbIngredients_;
}
double PlatCustom::getSupplement() const{
    return supplement_;
}
double PlatCustom::calculerSupplement() const{
    prix_ += supplement_;
}
friend ostream& operator<<(ostream& os, const PlatCustom& plat){
    os << plat.nom_ << " - " << plat.prix_ << " $ (" << plat.cout_ << "$ pour le restaurant)" << plat.nbIngredients << "nombre d'ingredients " <<  plat.getSupplement() << "supplement au prix" << endl;
	return os;
}
