/*
* Titre : Menu.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
* Modifie par: Sofia Alvarez (1894026) et Justin de Meulemeester ( )
* Date: 08 fevrier 2019
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>

using namespace std;

class Plat {
public:
	/// constructeurs
	Plat();
	Plat(string nom, double prix, double cout);

	///getters
	string getNom() const;
	double getPrix() const;
	double getCout() const;

	///setters
	void setNom(string nom);
	void setPrix(double prix);

	///Surcharges d'op�rateurs
	friend ostream& operator<<(ostream& out, const Plat& plat);
	friend bool operator<(const Plat& plat1, const Plat& plat2);


private:
	string nom_;
	double prix_;
	double cout_;

};

#endif // !PLAT_H
