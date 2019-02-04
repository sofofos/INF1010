/*
* Titre : Plat.h - Travail Pratique #1
* Date : 24 Janvier 2019
* Auteur : Sofia Alvarez (1894026) & Justin de Meulemeester(1897007)
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>

using namespace std;

/**
* Cette classe caractérise un plat par son nom, son prix et le prix de production.
*/
class Plat {
public:
	// constructeurs
	Plat();
	Plat(const string& nom, double prix, double cout);

	//getters 
	string getNom() const;
	double getPrix() const;
	double getCout() const;

	//setters 
	void setNom(const string& nom);
	void setPrix(double prix);

	//affichage
	void afficher() const;

private:
	string nom_;
	double prix_;
	double cout_;

};

#endif // !PLAT_H
