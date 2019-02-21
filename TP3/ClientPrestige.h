/*
* Titre : ClientPrestige.h - Travail Pratique #3
* Date : 11  F�vrier 2019
* Auteur : Fatou S. Mounzeo
*/
#ifndef CLIENT_PRESTIGE
#define CLIENT_PRESTIGE

#include "ClientRegulier.h"
enum AddressCode { Zone1, Zone2, Zone3 };
class ClientPrestige : public ClientRegulier {
public:
	ClientPrestige();
	ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, AddressCode addresse);

	//Accesseur 
	AddressCode getAddresseCode() const;

	//Autres Fonctions??
	friend ostream & operator<<(ostream & os, ClientPrestige client);
	string getAddressCodeString() const;



private:
	AddressCode addresse_;

};

#endif;

