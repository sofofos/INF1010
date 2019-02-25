/**********************************************************************
* Titre : clientPrestige.cpp - Travail Pratique #3
* Date : 11 Février 2019
* Auteur : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 24 Février 2019
************************************************************************/

#include "ClientPrestige.h"

//Constructeurs
ClientPrestige::ClientPrestige()
	:addresse_(Zone3) {
}

ClientPrestige::ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, AddressCode addresse)
	: ClientRegulier(nom, prenom, tailleGroupe, nbPoints), addresse_(addresse) {
	statut_ = Prestige;
}


//Accesseur 
AddressCode ClientPrestige::getAddresseCode() const {
	return addresse_;
}

string ClientPrestige::getAddressCodeString() const {
	switch (addresse_) {
	case Zone1:
		return "Zone1";
	case Zone2:
		return "Zone2";
	case Zone3:
		return "Zone3";
	}
}

ostream & operator<<(ostream & os, ClientPrestige client) {
	os << static_cast<ClientRegulier>(client) << "\t" << "Habite dans la " << client.getAddressCodeString() << endl;
	return os;
}
