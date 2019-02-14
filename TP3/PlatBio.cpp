#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout double ecotaxe) : Plat(nom, prix, cout, ecotaxe){}

double PlatBio::getEcoTaxe() const{
    return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe){
    ecoTaxe_ = ecoTaxe;
}

friend ostream& operator<<(ostream& os, const PlatBio& plat){
    os << plat.nom_ << " - " << plat.prix_ << " $ (" << plat.cout_ << "$ pour le restaurant)" << plat.ecotaxe << "$ en ecotaxe"<< endl;
    return os;
}
