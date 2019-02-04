/*
* Titre : Menu.h - Travail Pratique #1
* Date : 24 Janvier 2019
* Auteur : Sofia Alvarez (1894026) & Justin de Meulemeester(1897007)
*/

#ifndef MENU_H
#define MENU_H 

#include "Plat.h"
#include <fstream>

enum TypeMenu { Matin, Midi, Soir };
const int MAXPLAT = 5;

/**
* Cette classe caractérise un menu, ainsi il contiendra un tableau dynamique contenant des pointeurs
* vers des plats ainsi qu’un attribut issue d’un type énuméré
* permettant de déterminer le type de menu (Matin, Midi ou Soir).
*/
class Menu {
public:
	// constructeurs
	Menu();
	Menu(string fichier, TypeMenu type);

	// destructeur
	~Menu();

	//getters
	int getNbPlats() const;

	//affichage 
	void afficher() const;

	//methodes en plus
	Plat* trouverPlat(string& nom);
	void ajouterPlat(Plat& plat);
	void ajouterPlat(string& nom, double montant, double cout);
	bool lireMenu(string& fichier);

private:
	unsigned int capacite_;
	Plat** listePlats_;
	unsigned int nbPlats_;
	TypeMenu type_;

};

#endif // !MENU_H
