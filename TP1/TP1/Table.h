/*
* Titre : Table.h - Travail Pratique #1
* Date : 24 Janvier 2019
* Auteur : Sofia Alvarez (1894026) & Justin de Meulemeester(1897007)
*/

#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"
const  int MAXCAP = 5;

/**
* Cette classe caractérise une table du restaurant, elle a un identifiant, une liste de plats (la
* commande de la table), un nombre de places et un attribut permettant de déterminer si la table est
* libre ou non.
*/
class Table {
public:
	//constructeurs 
	Table();
	Table(int id, int nbPlaces);

	//destructeur
	~Table();

	//getters 
	int getId() const;
	int getNbPlaces() const;
	bool estOccupee() const;

	//setters 
	void libererTable();
	void placerClient();
	void setId(int id);

	//autres methodes 
	void commander(Plat* plat);
	double getChiffreAffaire() const;

	//affichage
	void afficher() const;
private:
	Plat * * commande_;
	unsigned int capacite_;
	unsigned int nbPlats_;

	int id_;
	unsigned int nbPlaces_;
	bool occupee_;
};
#endif // !TABLE_H
