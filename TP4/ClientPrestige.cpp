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
	:ClientRegulier(nom, prenom, tailleGroupe, nbPoints), adresse_(adresse)
{
}

ZoneHabitation ClientPrestige::getAdresseCode() const
{
	return adresse_;
}

void ClientPrestige::afficherClient(ostream & os) const
{	
	ClientRegulier::afficherClient(os);
}


double ClientPrestige :: getReduction(const Restaurant& res, double montant , bool estLivraison)
{   //TODO done
	double reduction = 0;
	if (nbPoints_ > SEUIL_DEBUT_REDUCTION) {
		reduction = (-montant) * TAUX_REDUC_PRESTIGE;
	}
	if (nbPoints_ < SEUIL_LIVRAISON_GRATUITE && estLivraison) {
		reduction += res.getFraisLivraison(adresse_);
	}
	return reduction;
}
