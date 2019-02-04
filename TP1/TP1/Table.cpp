/*
* Titre : Table.cpp - Travail Pratique #1
* Date : 24 Janvier 2019
* Auteur : Sofia Alvarez (1894026) & Justin de Meulemeester(1897007)
*/
#include "Table.h"

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

//Destructeur
Table::~Table() {
	delete[] commande_;
	commande_ = nullptr;
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

	delete[] commande_;
	commande_ = new Plat*[MAXCAP];		//Pour permettre aux prochains clients de commander.
	nbPlats_ = 0;
	occupee_ = false;
}

void Table::placerClient() {
	occupee_ = true;
}
void Table::setId(int id) {
	id_ = id;
}

/**
* Place un plat dans la commande.
*
* \param [in] plat
*        Un pointeur vers le plat à ajouter.
*/
void Table::commander(Plat* plat) {
	//Alloue plus d'espaces si il en manque.
	if (nbPlats_ >= capacite_) {

		unsigned int capaciteDouble = 2 * capacite_;
		Plat** commandeDouble = new Plat*[capaciteDouble];

		for (unsigned int i = 0; i < capacite_; i++)
			commandeDouble[i] = commande_[i];

		delete[] commande_;
		commande_ = commandeDouble;
		capacite_ = capaciteDouble;
	}
	//Ajoute le plat à la commande.
	commande_[nbPlats_] = plat;
	nbPlats_++;
}

/**
* Donne le chiffre d'affaire d'une table, c'est-à-dire la différence entre le prix et le cout de production d'un plat.
*
* retourne le chiffre d’affaire généré par la table.
*/
double Table::getChiffreAffaire() const {
	double chiffreAffaire = 0;
	for (unsigned i = 0; i < nbPlats_; i++) {
		chiffreAffaire += (commande_[i]->getPrix() - commande_[i]->getCout());
	}
	return chiffreAffaire;
}
/**
* Affiche la table, c'est-à-dire le numéro de la table, son état (libre ou occupée) ainsi que la commande
* placée par le client.
*/
void Table::afficher() const {
	cout << "\tLa table numero " << id_ << " est ";
	if (occupee_) {
		cout << "occupee. ";
		if (nbPlats_ == 0)
			cout << "Mais ils n'ont rien commande pour l'instant. \n \n";
		else {
			cout << "Voici la commande placee par les clients : \n";
			for (unsigned int i = 0; i < nbPlats_; i++)
				commande_[i]->afficher();
			cout << "\n";
		}
	}
	else
		cout << "libre. \n \n";
}