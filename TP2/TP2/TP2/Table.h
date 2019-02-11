/*
* Titre : Menu.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
* Modifie par: Sofia Alvarez (1894026) et Justin de Meulemeester ( )
* Date: 08 fevrier 2019
*/

#ifndef TABLE_H
#define TABLE_H

#include "Plat.h"
#include <vector>
const  int MAXCAP = 5;
class Table {
public:
	///constructeurs
	Table();
	Table(int id, int nbPlaces);


	///getters
	int getId() const;
	int getNbPlaces() const;
	int getnbClientATable() const;
	bool estPleine() const;
	bool estOccupee() const;

	///setters
	void libererTable(); // A MODIFIER
	void placerClient(int nbClients);
	void setId(int id);

	///autres methodes
	void commander(Plat* plat); // A MODIFIER
	double getChiffreAffaire() const;

	///affichage
	friend ostream& operator<<(ostream& out, const Table& plat);

private :
	//A MODIFIER
	vector<Plat*> commande_;
	int id_;
	int nbPlaces_;
	int nbClientsATable_;
};
#endif // !TABLE_H
