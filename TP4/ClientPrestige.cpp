/*********************************************************************
* Date : 25 février 2019
* Auteur : AbdeB
**********************************************************************
* Modifié par : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 21 Mars 2019
*********************************************************************/
#include "ClientPrestige.h"
#include "Restaurant.h"

ClientPrestige::ClientPrestige()
{
	adresse_ = ZoneHabitation::Zone3;
}

ClientPrestige::ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, int nbPoints, ZoneHabitation adresse)
	:ClientRegulier(nom, prenom, tailleGroupe, nbPoints)
{
   //TODO done
}

ZoneHabitation ClientPrestige::getAdresseCode() const
{
	return adresse_;
}

void ClientPrestige::afficherClient(ostream & os) const
{
        // TODO
	os << "Le client " << prenom_ << " " << nom_ << "a " << nbPoints_ << " points" << endl;
}
string ClientPrestige::getAdressCodeString() const
{
	string zone;
	switch (adresse_)
	{
	case ZoneHabitation::Zone1:
		zone = "Zone 1";
		break;
	case  ZoneHabitation::Zone2:
		zone = " Zone 2";
		break;
	case  ZoneHabitation::Zone3:
		zone = "Zone 3";
		break;

	default:
		zone = "erreur zone";
		break;
	}
	return zone;
}
double ClientPrestige :: getReduction(const Restaurant& res, double montant , bool estLivraison)
{   //TODO done
	double reduction;
	if (nbPoints_ > SEUIL_DEBUT_REDUCTION) {
		reduction = (-montant) * TAUX_REDUC_PRESTIGE;
	}
	if (nbPoints_ < SEUIL_LIVRAISON_GRATUITE) {
		reduction += res.getFraisLivraison[adresse_];
	}
	return reduction;
}
