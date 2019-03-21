/*********************************************************************
* Date : 25 février 2019
* Auteur : AbdeB
**********************************************************************
* Modifié par : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 21 Mars 2019
*********************************************************************/
#include "PlatBioVege.h"

PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe, double vitamines, double proteines, double mineraux) 
	: PlatBio(nom, prix, cout, ecotaxe), Vege(nom, vitamines, proteines, mineraux)
{ // TODO done
}
PlatBioVege:: ~PlatBioVege(){}

//TODO
void PlatBioVege::afficherPlat(ostream & os) const
{   //TODO done
	PlatBio::afficherPlat(os);
	os << "ET ";
	Vege::afficherVege(os);
}

Plat * PlatBioVege::clone() const
{ //TODO done
	Plat* clonePlat = new Plat(Plat::nom_, prix_, cout_);
	return clonePlat;
}

double PlatBioVege::calculerApportNutritif() const
{
   //TODO done
	return (vitamines_*proteines_ / mineraux_)*RAPPORT_NUTRITIF*AVANTAGE_SANS_PESTICIDE;
}
