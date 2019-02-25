/**********************************************************************
* Titre : clientRegulier.cpp - Travail Pratique #3
* Date : 11 Février 2019
* Auteur : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 24 Février 2019
************************************************************************/

#include "ClientRegulier.h"

//Constructeurs

ClientRegulier::ClientRegulier()
	:nbPoints_(0) {
}

ClientRegulier::ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints)
	: Client(nom, prenom, tailleGroupe), nbPoints_(nbPoints) {
	statut_ = Fidele;
}

//Accesseurs
int ClientRegulier::getNbPoints() const {
	return nbPoints_;
}

//Autres Méthodes
void ClientRegulier::augmenterNbPoints(int bonus) {
	nbPoints_ += bonus;
}

ostream & operator<<(ostream & os, const ClientRegulier& client) {
	os << static_cast<Client>(client) << " Possede " << client.nbPoints_ << " points.\n";
	return os;
}