/*
* Titre : Menu.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
* Modifie par: Sofia Alvarez (1894026) et Justin de Meulemeester ( )
* Date: 08 fevrier 2019
*/

#include "Menu.h"

//constructeurs

Menu::Menu() {
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	type_ = Matin;
	for(int i = 0; i < MAXPLAT; i++){
		listePlats.pushback(new Plat());
	}
}

Menu::Menu(string fichier, TypeMenu type) {
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	type_ = type;
	for(int i = 0; i < MAXPLAT; i++){
		listePlats.pushback(new Plat());
	}

	//lecture du fichier -- creation du menu
	lireMenu(fichier);
}

Menu::Menu(const Menu& menu){
	capacite = menu.capacite_;
	nPlats = menu.nPlats;
	type = menu.type_;
	listePlats = menu.listePlats;

}
//destructeur
Menu::~Menu() {
	// A MODIFIER
	for (int i = 0; i < nbPlats_; i++)
		delete listePlats[i];
	}

}

//getters

int Menu::getNbPlats() const {
	return nbPlats_;
}

//autres methodes


bool Menu::lireMenu(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (!file) {
		//cout << "ERREUR : le fichier n'a pas pu etre ouvert" << endl;
		return false;
	}
	else {
		string type;
		switch (type_) {
		case Matin :
			type = "-MATIN";
			break;
		case Midi :
			type = "-MIDI";
			break;
		case Soir :
			type = "-SOIR";
			break;
		}
		string ligne;

		string nom;

		string prixString;
		double prix;

		string coutString;
		int cout;


		// lecture
		while (!file.eof()) {
			getline(file, ligne);
			//trouver le bon type de menu (section)
			if (ligne == type){
				//commencer a lire -- s'arrete si fin du fichier ou encore si on arrive a une nouvelle section du menu
				getline(file, ligne);
				int curseur;
				while (ligne[0] != '-' && !file.eof()) {
					//trouver le nom
					for (int i = 0; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						nom += ligne[i];
					}
					//trouver le prix

					for (int i = curseur + 1; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						prixString += ligne[i];

					}
					//passer le prixString en double --- indice dans l'enonce
					prix = stof(prixString.c_str());

					for (int i = curseur + 1; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ')
							break;
						coutString += ligne[i];
					}

					cout =int( stof(coutString.c_str()));

					ajouterPlat( Plat(nom, prix, cout));
					nom = "";
					prixString = "";
					coutString = "";

					getline(file, ligne);
				}
			}
		}

		file.close();
		return true;
	}
}

Plat* Menu::trouverPlatMoinsCher() const
{
	Plat minimum(*listePlats[0]);
	int found = -1;

	for (unsigned i = 0; i < listePlats.size(); ++i)
	{
		if (*listePlats[i] < minimum)
		{
			minimum = *listePlats[i];
			found = i;
		}
	}

	return listePlats[found];

}

Plat* Menu::trouverPlat(const string& nom) const {
	for (int i = 0; i < nbPlats_; i++) {
		if (listePlats[i]->getNom() == nom)
			return listePlats[i];
	}
	return nullptr;
}

friend ostream& operator<<(ostream& out, const Menu& menu){
	out << "Menu du: " menu.type_ << " - " << menu.nbPlats_ <<
	"  -  " << endl;
	for(int i = 0; i < menu.nbPlats_; i++){
		out << "\t" << listePlats[i] << endl;
 	}
}
Plat& Plat::operator+=(const Plat& plat){
	return listePlats.pushback(&plat);
}

Menu& Menu::operator=(const Menu& menu){
	if( thus != &menu){
		for(int i = 0; 0 <listePlats.size();i++){
			delete listePlats[i];
			listePlats[i] = nullptr;
		}
		type_ = menu.type;
		listePlats = menu.listePlats;
	}
	return *this;

}
//page 603 constructeur par copie in Big C++
