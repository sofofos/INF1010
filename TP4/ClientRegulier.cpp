/*********************************************************************
* Date : 25 février 2019
* Auteur : AbdeB
**********************************************************************
* Modifié par : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 21 Mars 2019
*********************************************************************/
#include "ClientRegulier.h"

ClientRegulier::ClientRegulier()
{
	nbPoints_ = 0;
}

ClientRegulier::ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int npoints)
	:Client(nom, prenom, tailleGroupe)
{ 
}
ClientRegulier::~ClientRegulier() {}

int ClientRegulier::getNbPoints() const
{
	return nbPoints_;
}


void ClientRegulier::augmenterNbPoints(int bonus)
{
	nbPoints_ += bonus;
}


void ClientRegulier::afficherClient(ostream & os) const
{
	Client::afficherClient(os);
}

double ClientRegulier::getReduction(const Restaurant & res, double montant, bool estLivraison)
{
	double reduction;
	//TODO
	if (nbPoints_ > SEUIL_DEBUT_REDUCTION) {
		reduction = (-montant * TAUX_REDUC_REGULIER);
	}
	return reduction;
}
