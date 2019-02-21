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