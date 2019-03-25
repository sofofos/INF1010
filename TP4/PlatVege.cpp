/*********************************************************************
* Date : 25 février 2019
* Auteur : AbdeB
**********************************************************************
* Modifié par : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 21 Mars 2019
*********************************************************************/
#include "PlatVege.h"


//TODO done
PlatVege::PlatVege(string nom, double prix, double cout, double vitamines, double proteines, double mineraux)
	:Plat(nom, prix, cout), Vege(nom, vitamines, proteines, mineraux)
{
	setTaxe();

}
PlatVege::~ PlatVege(){}

double PlatVege::getTaxe() const {
	return taxe_;
}

void PlatVege::setTaxe() {
	taxe_ = 0.07;
}

Plat* PlatVege::clone()const
{ //TODONE
	PlatVege* clonePlat = new PlatVege(Plat::nom_, prix_, cout_,vitamines_,proteines_,mineraux_);
	return clonePlat;
}


void PlatVege::afficherPlat(ostream & os) const
{   //TODO
	Plat::afficherPlat(os);
	Vege::afficherVege(os);
}

double PlatVege::calculerApportNutritif() const
{
	//TODO done
	return (vitamines_*proteines_ / mineraux_)*RAPPORT_NUTRITIF;
}
