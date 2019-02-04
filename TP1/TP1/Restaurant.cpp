/*
* Titre : Restaurant.cpp - Travail Pratique #1
* Date : 24 Janvier 2019
* Auteur : Sofia Alvarez (1894026) & Justin de Meulemeester(1897007)
*/

#include "Restaurant.h"


// Constructeurs
Restaurant::Restaurant()
	:nom_(new string("inconnu")) {  //Pour ne pas appeler inutilement le constructeur par defaut.

	momentJournee_ = Matin;
	chiffreAffaire_ = 0.0;

	menuMatin_ = new Menu;
	menuMidi_ = new Menu;
	menuSoir_ = new Menu;

	capaciteTables_ = INTTABLES;
	tables_ = new Table*[INTTABLES];
	nbTables_ = 0;
}

Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment)
	:menuMatin_(new Menu(fichier, Matin)),  //Liste d'initialisation pour ne pas appeler
	menuMidi_(new Menu(fichier, Midi)),    //inutilement le constructeur par defaut
	menuSoir_(new Menu(fichier, Soir))     //de la classe Menu.
{
	nom_ = &nom;
	momentJournee_ = moment;
	chiffreAffaire_ = 0;
	capaciteTables_ = INTTABLES;
	tables_ = new Table*[INTTABLES];
	nbTables_ = 0;
	lireTable(fichier);
}
//Destructeur
Restaurant::~Restaurant() {
	delete[] tables_;
	tables_ = nullptr;

	delete menuMatin_;
	menuMatin_ = nullptr;
	delete menuMidi_;
	menuMatin_ = nullptr;
	delete menuSoir_;
	menuMatin_ = nullptr;
}

//Setters
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}

//Getters
string Restaurant::getNom() const {
	return *nom_;
}

TypeMenu Restaurant::getMoment() const {
	return momentJournee_;
}
/**
* Permet de créer les tables, elle est appelée dans le constructeur par paramètre.
*
* \param [in] fichier
*        Le fichier contenant les tables.
*/
void Restaurant::lireTable(string &fichier) {
	//Ouverture et verification du fichier
	fstream fichierEntree;
	fichierEntree.open(fichier);
	if (fichierEntree.fail())
		cout << "ERREUR : Impossible d'ouvrir le fichier \n";

	string ligne;
	do {
		getline(fichierEntree, ligne);		//Continue de lire les lignes du fichier, jusqu'à ce 
	} while (ligne != "-TABLES");			//qu'il arrive à la section des tables.

	int id;
	int nbPlaces;

	while (!(fichierEntree.eof())) {		//Tant qu'il n'arrive pas à la fin du fichier
		fichierEntree >> id >> nbPlaces;	//la lecture se poursuit.
		ajouterTable(id, nbPlaces);
	}
	fichierEntree.close(); //Fermeture du fichier.
}

/**
* Ajoute une table à la liste de tables.
*
* \param [in] id
*        Le numéro de la table.
* \param [in] nbPlaces
*		 Le nombres de places à la table.
*/
void Restaurant::ajouterTable(int id, int nbPlaces) {
	//Alloue plus d'espaces si il en manque.
	if (nbTables_ >= capaciteTables_) {

		unsigned int capaciteDouble = 2 * capaciteTables_;
		Table** tablesDouble = new Table*[capaciteDouble];

		for (unsigned int i = 0; i < capaciteTables_; i++)
			tablesDouble[i] = tables_[i];

		delete[] tables_;
		tables_ = tablesDouble;
		capaciteTables_ = capaciteDouble;
	}
	//Ajoute la table à la liste.
	tables_[nbTables_] = new Table(id, nbPlaces);
	nbTables_++;
}
/**
* Libère la table et met à jour le chiffre d'affaire du restaurant.
*
* \param [in] id
*        Le numéro de la table.
*/
void Restaurant::libererTable(int id) {
	for (unsigned int i = 0; i < nbTables_; i++) {
		if (tables_[i]->getId() == id) {
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			tables_[i]->libererTable();
			break;
		}
	}
}

/**
* Ajoute un plat à la commande de la table et s'assure de la légitimité de la commande.
*
* \param [in] nom
*        Le nom du plat.
* \param [in] idTable
*		 Le numéro de la table.
*/
void Restaurant::commanderPlat(string& nom, int idTable) {
	//Determine le menu dans lequel chercher, selon le moment de la journée.
	Menu* unMenu = nullptr;
	switch (momentJournee_) {
	case Matin:
		unMenu = menuMatin_;
		break;
	case Midi:
		unMenu = menuMidi_;
		break;
	case Soir:
		unMenu = menuSoir_;
		break;
	default:
		break;
	}

	for (unsigned int i = 0; i < nbTables_; i++) {

		bool estBonneTable = tables_[i]->getId() == idTable;
		bool estOccupee = tables_[i]->estOccupee();
		bool estUnPlat = !(unMenu->trouverPlat(nom) == nullptr);

		//S'assure que la commande provient d'une table occupée et qu'elle représente un plat sur le menu.
		if (estBonneTable && estOccupee && estUnPlat) {
			tables_[i]->commander(unMenu->trouverPlat(nom));
			break; //Une commande légitime sort de la boucle.
		}

		if (estBonneTable) {
			cout << "ERREUR : Table non occupee ou plat introuvable. \n";
			break; //Une commande non légitime affiche un message d'erreur et sort de la boucle.
		}
	}
}

/**
* Place les clients à une table de manière intelligente, c'est-à-dire en minimisant le nombre de places
* libres à chaque table.
*
* \param [in] nbClients
*        Le nombre de clients à placer.
*/
void Restaurant::placerClients(int nbClients) {

	int meilleureDifference = NOMBRE_TRES_GRAND;						//La difference commence très grande.
	int meilleurePosition = -1;
	for (unsigned int i = 0; i < nbTables_; i++) {
		if (!(tables_[i]->estOccupee())) {
			int difference = tables_[i]->getNbPlaces() - nbClients;
			if (difference > 0 && difference < meilleureDifference) {	//S'il y a plus de places
				meilleureDifference = difference;						//que de clients, et que la difference
				meilleurePosition = i;									//entre les deux est la plus petite,
			}															//alors on ajuste les paramètres.
		}
	}
	//Si meilleurePosition n'est plus à -1, alors on place le client à la meilleure table.
	if (meilleurePosition != -1)
		tables_[meilleurePosition]->placerClient();
	//Sinon, alors il n'y a plus de places disponibles.
	else
		cout << "ERREUR : Il n'y a plus/pas de places disponibles pour le client. \n";
}

/**
* Affiche le restaurant, c'est-à-dire le nom du restaurant, son chiffre d'affaire, la liste des tables
ainsi que son menu.
*/
void Restaurant::afficher() const {
	cout << "Le restaurant " << *nom_;
	if (chiffreAffaire_ == 0)
		cout << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule. \n";
	else
		cout << " a fait un chiffre d'affaire de : " << chiffreAffaire_ << "$\n";

	cout << "-Voici les tables :\n";
	for (unsigned int i = 0; i < nbTables_; i++)
		tables_[i]->afficher();

	cout << "\n-Voici son menu : \n";
	menuMatin_->afficher();
	menuMidi_->afficher();
	menuSoir_->afficher();
}
