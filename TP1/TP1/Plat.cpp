/*
* Titre : Plat.cpp - Travail Pratique #1
* Date : 24 Janvier 2019
* Auteur : Sofia Alvarez (1894026) & Justin de Meulemeester(1897007)
*/
#include "Plat.h"


//Constructeurs
Plat::Plat() {
	nom_ = "inconnu";
	prix_ = 0.0;
	cout_ = 0.0;
}

Plat::Plat(const string& nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}
//Getters
string Plat::getNom() const {
	return nom_;
}

double Plat::getPrix() const {
	return prix_;
}

double Plat::getCout() const {
	return cout_;
}

//Setters
void Plat::setNom(const string& nom) {
	nom_ = nom;
}

void Plat::setPrix(double prix) {
	prix_ = prix;
}


/**
* Affiche le plat, c'est-à-dire le nom, le prix et le cout de production pour le restaurant
*/
void Plat::afficher() const {
	cout << "\t" << nom_ << " - " << prix_ << " $ (" << cout_ << "$ pour le restaurant) \n";
}
