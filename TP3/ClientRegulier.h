/**********************************************************************
* Titre : clientRegulier.h - Travail Pratique #3
* Date : 11 F�vrier 2019
* Auteur : Fatou S. Mounzeo
**********************************************************************
* Modifi� par : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 24 F�vrier 2019
************************************************************************/
#ifndef CLIENT_REG
#define CLIENT_REG
#include "Client.h"
#include <vector>

const double TAUX_REDUC_REGULIER = 0.1;
const double TAUX_REDUC_PRESTIGE = 0.2;
const double SEUIL_DEBUT_REDUCTION = 75;
const double SEUIL_LIVRAISON_GRATUITE = 200;

class ClientRegulier : public Client {
public:
	ClientRegulier();
	ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints);


	//Accesseurs
	int getNbPoints() const;


	//Autres M�thodes
	void augmenterNbPoints(int bonus);
	friend ostream & operator<<(ostream & os, const ClientRegulier& client);


protected:
	int nbPoints_;
};
#endif
