#include "Table.h"
#include <iostream>

//Constructeurs
Table::Table() {
	id_ = -1;
	nbPlaces_ = 1;
	capacite_ = MAXCAP;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];
	nbPlats_ = 0;
}

Table::Table(int id, int nbPlaces) {
	id_ = id;
	nbPlaces_ = nbPlaces;
	capacite_ = MAXCAP;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];
	nbPlats_ = 0;
}
//Getters
int Table::getId() const {
	return id_;
}
int Table::getNbPlaces() const {
	return nbPlaces_;
}

bool Table::estOccupee() const {
	return occupee_;
}

//Setters
void Table::libererTable() {
	for (unsigned i = 0; i < nbPlats_; i++) {
		delete commande_[i];
		commande_[i] = nullptr;
	}
	delete[] commande_;
	commande_ = nullptr;
	occupee_ = false;
}
void Table::placerClient() {
	occupee_ = true;
}
void Table::setId(int id) {
	id_ = id;
}

//Autres méthodes
void Table::commander(Plat* plat) {
	if (nbPlats_ >= capacite_) {
		unsigned int capaciteDouble = 2 * capacite_;
		Plat** commandeDouble = new Plat*[capaciteDouble];
		for (unsigned int i = 0; i < capacite_; i++) {
			commandeDouble[i] = commande_[i];
			delete commande_[i];
		}
		delete[] commande_;
		commande_ = commandeDouble;
		capacite_ = capaciteDouble;
	}
	commande_[nbPlats_] = plat;
	nbPlats_++;
}

	
double Table::getChiffreAffaire() const {
	double chiffreAffaire = 0;
	for (unsigned i = 0; i < nbPlats_; i++) {
			chiffreAffaire += (commande_[i]->getPrix() - commande_[i]->getCout());
	}
	return chiffreAffaire;
}

void Table::afficher() {
	cout << "La table numero " << id_ << " est ";
	if (occupee_)
		cout << "occupee. ";
	else
		cout << "libre. ";
	if (nbPlats_ == 0)
		cout << "Mais ils n'ont rien commande pour l'instant"
	


}