/*
* Titre : Table.cpp - Travail Pratique #3
* Date : 11 F�vrier 2019
* Auteur :Fatou S. MOUNZEO
* Modifier par: Sofia Alvarez (1894026) & Justin de Meulemeester(######)
*/

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
    os  << "\t" << " comprend une taxe ecologique de: "
        << plat.ecoTaxe_ << "$" << endl;
    return os;
}
