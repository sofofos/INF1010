/*********************************************************************
* Date : 25 février 2019
* Auteur : AbdeB
**********************************************************************
* Modifié par : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 21 Mars 2019
*********************************************************************/
#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe)
		: Plat(nom, prix, cout), ecoTaxe_(ecotaxe)
{
}


PlatBio::~ PlatBio(){}

double PlatBio::getEcoTaxe() const
{
	return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe)
{
	ecoTaxe_ = ecoTaxe;
}

//TODO done
Plat * PlatBio:: clone () const
{
	Plat* clonePlat = new Plat(nom_, prix_, cout_);
	return clonePlat;

}
double PlatBio:: getPrixDeRevient()
{ //TODO done
	return prix_ - cout_ + ecoTaxe_;
}

void PlatBio::afficherPlat(ostream& os) const
{
    //TODO done
	Plat::afficherPlat(os);
	os << "Plat Bio   comprend une Taxe ecologique de: " << ecoTaxe_ << "$" << endl;
}
