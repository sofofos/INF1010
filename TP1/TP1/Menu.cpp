/*
* Titre : Menu.cpp - Travail Pratique #1
* Date : 24 Janvier 2019
* Auteur : Sofia Alvarez (1894026) & Justin de Meulemeester(1897007)
*/

#include "Menu.h"


//Constructeurs
Menu::Menu() {
	capacite_ = MAXPLAT;
	listePlats_ = new Plat*[MAXPLAT];
	nbPlats_ = 0;
	type_ = Matin;
}
Menu::Menu(string fichier, TypeMenu type) {
	type_ = type;
	capacite_ = MAXPLAT;
	listePlats_ = new Plat*[MAXPLAT];
	nbPlats_ = 0;
	lireMenu(fichier);
}

//Destructeur
Menu::~Menu() {
	delete[] listePlats_;
	listePlats_ = nullptr;
}

//Getters
int Menu::getNbPlats() const {
	return nbPlats_;
}

/**
* Affiche le menu, c'est-à-dire la liste de plats du matin, du midi et du soir.
*/
void Menu::afficher() const {
	switch (type_) {
	case Matin:
		cout << "Matin :\n";
		break;
	case Midi:
		cout << "Midi :\n";
		break;
	case Soir:
		cout << "Soir :\n";
		break;
	default:
		break;
	}
	for (unsigned int i = 0; i < nbPlats_; i++)
		listePlats_[i]->afficher();
}

/**
* Trouve un plat parmi une liste de plats, grâce au nom du plat.
*
* \param [in] nom
*        Le nom du plat.
*
* retourne un pointeur vers le plat en question (pointeur nul si le plat n'est pas trouvé).
*/
Plat* Menu::trouverPlat(string& nom) {
	for (unsigned int i = 0; i < nbPlats_; i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}
	return nullptr; //Si ca ne trouve pas le plat, ca retourne nullPtr.
}

/**
* Ajoute un plat à la liste de plats.
*
* \param [in] plat.
*        Le plat à ajouter.
*/
void Menu::ajouterPlat(Plat& plat) {
	//Alloue plus d'espaces si il en manque.
	if (nbPlats_ >= capacite_) {
		unsigned int capaciteDouble = 2 * capacite_;
		Plat** listePlatsDouble = new Plat*[capaciteDouble];

		for (unsigned int i = 0; i < capacite_; i++)
			listePlatsDouble[i] = listePlats_[i];

		delete[] listePlats_;
		listePlats_ = listePlatsDouble;
		capacite_ = capaciteDouble;
	}
	//Ajoute le plat à la liste.
	listePlats_[nbPlats_] = &plat;
	nbPlats_++;
}

/**
* Ajoute un plat à la liste de plats.
*
* \param [in] nom
*        Le nom du plat.
* \param [in] montant
*		 Le prix du plat.
* \param [in] cout
*		 Le cout du plat.
*/
void Menu::ajouterPlat(string& nom, double montant, double cout) {
	//Alloue plus d'espaces si il en manque.
	if (nbPlats_ >= capacite_) {
		unsigned int capaciteDouble = 2 * capacite_;
		Plat** listePlatsDouble = new Plat*[capaciteDouble];

		for (unsigned int i = 0; i < capacite_; i++)
			listePlatsDouble[i] = listePlats_[i];

		delete[] listePlats_;
		listePlats_ = listePlatsDouble;
		capacite_ = capaciteDouble;
	}
	//Ajoute le plat à la liste.
	listePlats_[nbPlats_] = new Plat(nom, montant, cout);
	nbPlats_++;
}

/**
* Permet de remplir le menu, en lisant un fichier.
*
* \param [in] fichier
*        Le fichier contenant le menu.
*
* retourne un bool qui indique si le fichier a bien été lu.
*/
bool Menu::lireMenu(string& fichier) {
	//Ouverture et verification du fichier.
	fstream fichierEntree;
	fichierEntree.open(fichier);
	if (fichierEntree.fail())
		return false;

	//Détermine le string qui marque le début de la section à lire.
	string strMenu;
	switch (type_) {
	case Matin:
		strMenu = "-MATIN";
		break;
	case Midi:
		strMenu = "-MIDI";
		break;
	case Soir:
		strMenu = "-SOIR";
		break;
	default:
		break;
	}
	string ligne;
	do {
		getline(fichierEntree, ligne); //Continue de lire les lignes du fichier, jusqu'à ce 
	} while (ligne != strMenu);        //la ligne correspond à celle de strMenu.

	char unChar;
	string nom;
	double prix;
	double cout;
	string finDeLigne;

	while (true) {
		fichierEntree.get(unChar);
		if (unChar == '-')						//Verifie si le prochain caractère est un tiret.
			break;								//Si oui, la boucle se termine
		else
			fichierEntree.unget();				//Si non, on unget unChar pour ne pas sauter un caractere.

		fichierEntree >> nom >> prix >> cout;
		getline(fichierEntree, finDeLigne);		//Lit le caractere de fin de ligne
												//pour passer a la prochaine ligne.
		ajouterPlat(nom, prix, cout);
	}
	fichierEntree.close();						//Fermeture du fichier.
	return true;
}