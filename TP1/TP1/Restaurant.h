/*
* Titre : Restaurant.h - Travail Pratique #1
* Date : 24 Janvier 2019
* Auteur : Sofia Alvarez (1894026) & Justin de Meulemeester(1897007)
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Table.h"
const int INTTABLES = 6;
const int NOMBRE_TRES_GRAND = 999999;

/**
* Cette classe caractérise un restaurant, avec un ensemble de tables, 3 menus en fonction du
* moment de la journée et un chiffre d’affaire.
*/
class Restaurant {
public:
	//constructeurs 
	Restaurant();
	Restaurant(string& fichier, string& nom, TypeMenu moment);

	//destructeur
	~Restaurant();

	//setters 
	void setMoment(TypeMenu moment);

	//getters 
	string getNom() const;
	TypeMenu getMoment() const;

	//Autres methodes 
	void lireTable(string& fichier);
	void ajouterTable(int id, int nbPlaces);
	void libererTable(int id);
	void commanderPlat(string& nom, int idTable);
	void placerClients(int nbClients);

	//affichage 
	void afficher() const;

private:
	string * nom_;

	double chiffreAffaire_;
	TypeMenu momentJournee_;

	//differents menus en fonction du moment de la journee
	Menu* menuMatin_;
	Menu* menuMidi_;
	Menu* menuSoir_;

	//liste des tables 
	unsigned int capaciteTables_;
	Table** tables_;
	unsigned int nbTables_;

};
#endif // !RESTAURANT_H
