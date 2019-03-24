/*********************************************************************
* Date : 25 février 2019
* Auteur : AbdeB
**********************************************************************
* Modifié par : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 21 Mars 2019
*********************************************************************/
#include "ClientOccasionnel.h"

ClientOccasionnel::ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe)
	:Client(nom, prenom, tailleGroupe)
{ // TODO done
}
ClientOccasionnel::~ClientOccasionnel(){}

int ClientOccasionnel::getNbPoints() const
{	//TODO done
	return 0;
}

void ClientOccasionnel::afficherClient(ostream & os) const
{	//TODO done
	Client::afficherClient(os);
}
double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison)
{
	return 0;
}

