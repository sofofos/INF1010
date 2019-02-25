/**********************************************************************
* Titre : client.cpp - Travail Pratique #3
* Date : 11 Février 2019
* Auteur : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 24 Février 2019
************************************************************************/
#include "Client.h"

//Constructeurs
Client::Client()
	:nom_("inconnu"), prenom_("inconnu"), statut_(Occasionnel) {
}

Client::Client(string nom, string prenom, int tailleGroupe)
	: nom_(nom), prenom_(prenom), tailleGroupe_(tailleGroupe), statut_(Occasionnel) {
}

// Accesseurs
StatutClient Client::getStatut() const {
	return statut_;
}

int Client::getTailleGroupe() const {
	return tailleGroupe_;
}

string Client::getNom() const {
	return nom_;
}

string Client::getPrenom() const {
	return prenom_;
}

//Autres méthodes
string Client::convertirStatutString() const {
	switch (statut_) {
	case Occasionnel:
		return "Occasionnel";
	case Fidele:
		return "Fidele";
	case Prestige:
		return "Prestige";
	
	}
}

ostream & operator<<(ostream & os, const Client& client) {
	os << "\t-" << client.prenom_ << " " << client.nom_  << " " << client.prenom_<< " statut: " << client.convertirStatutString();
	return os;
}