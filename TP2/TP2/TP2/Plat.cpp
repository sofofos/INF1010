/*
* Titre : Plat.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Plat.h"

//constructeurs
Plat::Plat() {
	nom_ = "Inconnu";
	prix_ = 0;
	cout_ = 0;
}

Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}
//getters

string Plat::getNom() const {
	return nom_;
}

double Plat::getPrix() const {
	return prix_;
}

double Plat::getCout() const {
	return cout_;
}
//setters
void Plat::setNom(string nom) {
	nom_ = nom;
}

void Plat::setPrix(double prix) {
	prix_ = prix;
}


//Surcharges d'op�rateur

ostream& operator<<(ostream& out, const Plat& plat) {
	out << plat.nom_ << " - " << plat.prix_ << " $ (" << plat.cout_ << "$ pour le restaurant)" << endl;
	return out;
}


bool operator<(const Plat& plat1, const Plat& plat2) {
	return (plat1.getPrix() < plat2.getPrix());
}