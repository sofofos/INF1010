/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include "Plat.h"
#include "Vege.h"
#include "gestionnaireGenerique.h"
#include "Foncteur.h"

#include <utility>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

class GestionnairePlats : public GestionnaireGenerique< pair<string, Plat*>, map<string, Plat*>>
{
public:
	GestionnairePlats(const string& nomFichier, TypeMenu type); 
	GestionnairePlats(GestionnairePlats* gestionnaire); 

	~GestionnairePlats(); 

	TypeMenu getType() const;

	Plat* allouerPlat(Plat* plat); 

	Plat* trouverPlatMoinsCher() const; 
	Plat* trouverPlatPlusCher() const; 

	Plat* trouverPlat(const string& nom) const; 
	vector<pair<string, Plat*>> getPlatsEntre(double borneInf, double borneSup);
	void lirePlats(const string& nomFichier, TypeMenu type);
	pair<string, Plat*> lirePlatDe(LectureFichierEnSections& fichier);

	void afficherPlats(ostream& os);

private:
	TypeMenu type_;
};