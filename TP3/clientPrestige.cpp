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
	default:
		break;
	}
}

ostream & operator<<(ostream & os, ClientPrestige client) {
	os << static_cast<Client>(client) << "\t" << "Habite dans la " << client.getAddressCodeString() << endl;
	return os;
}
