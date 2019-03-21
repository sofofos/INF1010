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
{ // TODO
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
	//TODO
}

double ClientRegulier::getReduction(const Restaurant & res, double montant, bool estLivraison)
{
	//TODO
}
