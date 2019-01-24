#include "Table.h"
#include <iostream>

//Constructeurs
Table::Table() {
	id_ = -1;
	nbPlaces_ = 1;
	capacite_ = MAXCAP;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];
}

Table::Table(int id, int nbPlaces) {
	id_ = id;
	nbPlaces_ = nbPlaces;
	capacite_ = MAXCAP;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];
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

}