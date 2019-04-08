/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/

#include "Restaurant.h"
#include "LectureFichierEnSections.h"
#include "debogageMemoire.hpp"
#include <cassert>
using namespace std;

//constructeurs 
Restaurant::Restaurant() :
	Restaurant{"menu.txt", "Inconnu", TypeMenu::Matin}
{
}

Restaurant::Restaurant(const string& nomFichier, string_view nom, TypeMenu moment) :
	nom_{nom},
	momentJournee_{moment},
	chiffreAffaire_{0},
	menuMatin_{new GestionnaireGenerique{nomFichier, TypeMenu::Matin}},
	menuMidi_ {new GestionnaireGenerique{nomFichier, TypeMenu::Midi }},
	menuSoir_ {new GestionnaireGenerique{nomFichier, TypeMenu::Soir }},
	fraisLivraison_{}
{
	tables_->lireTables(nomFichier); 
	lireAdresses(nomFichier);
}

// Destructeur.
Restaurant::~Restaurant()
{
	delete menuMatin_;
	delete menuMidi_;
	delete menuSoir_;
	set<Table*> ens = tables_->getConteneur();
	for (auto itr = ens.begin(); itr != ens.end(); itr++) {
		delete *itr;
	}
}


// Setters.

void Restaurant::setMoment(TypeMenu moment)
{
	momentJournee_ = moment; 
}

void Restaurant::setNom(string_view nom)
{
	nom_ = nom;
}

 void  Restaurant::setChiffreAffaire( double chiffre)
{ chiffreAffaire_ = chiffre;
}
// Getters.

string Restaurant::getNom() const
{
	return nom_; 
}

TypeMenu Restaurant::getMoment() const
{
	return momentJournee_; 
}


// Autres methodes.

void Restaurant::libererTable(int id)
{
	if (Table* table = tables_->getTable(id)) {
		chiffreAffaire_ += table->getChiffreAffaire(); 
		chiffreAffaire_ += calculerReduction(table->getClientPrincipal(), table->getChiffreAffaire(), id == tables_[INDEX_TABLE_LIVRAISON]->getId());
		table->libererTable(); 
	}
}

ostream& operator<<(ostream& os, const Restaurant& restaurant)
{
	os << "Le restaurant " << restaurant.getNom();
	if (restaurant.chiffreAffaire_ != 0)
		os << " a fait un chiffre d'affaire de : " << restaurant.chiffreAffaire_ << "$" << endl;
	else
		os << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;

	os << "-Voici les tables : " << endl;

	restaurant.tables_->afficherTables(os);
	

	os << "-Voici son menu : " << endl;
	for (TypeMenu typeMenu : { TypeMenu::Matin, TypeMenu::Midi, TypeMenu::Soir }) {
		GestionnairePlats* menu = restaurant.getMenu(typeMenu);
		os << restaurant.getNomTypeMenu(typeMenu) << ": " << endl;
		restaurant.getMenu(typeMenu)->afficherPlats(os);
		os << "Le plat le moins cher est: " << endl;
		menu->trouverPlatMoinsCher()->afficherPlat(os);
		os << endl;
	}
		
	return os;
}

void Restaurant::commanderPlat(string_view nom, int idTable)
{
	if (Table* table = tables_->getTable(idTable); table && table->estOccupee())
		if (Plat* plat = menuActuel()->trouverPlat(nom)) {
			table->commander(plat);
			return;
		}
	cout << "Erreur : table vide ou plat introuvable." << endl << endl;
}

bool Restaurant::operator <(const Restaurant& autre) const 
{
	return chiffreAffaire_ < autre.chiffreAffaire_;
}


bool Restaurant::placerClients(Client* client)
{
	const int tailleGroupe = client->getTailleGroupe();

	Table* meilleureTable = tables_->getMeilleureTable(tailleGroupe);

	if (meilleureTable != nullptr && meilleureTable->estOccupee == false) {
		meilleureTable->setClientPrincipal(client);
		client->setTable(meilleureTable);
		meilleureTable->placerClients(tailleGroupe);
		return true;
	}
	else
		return false;
}

bool Restaurant::livrerClient(Client* client, const vector<string>& commande)
{
	if (dynamic_cast<ClientPrestige*>(client)) {

		Table* table = tables_->getTable(ID_TABLE_LIVRAISON);
		table->setClientPrincipal(client);

		table->placerClients(1);

		for (unsigned int i = 0; i < commande.size(); i++) {
			commanderPlat(commande[i], INDEX_TABLE_LIVRAISON);
		}

		libererTable(INDEX_TABLE_LIVRAISON);
		return true;
	}
	else
		return false;
}
		
		


double Restaurant::calculerReduction(Client* client, double montant, bool estLivraison)
{
    return client->getReduction(*this, montant, estLivraison);
}

double Restaurant::getFraisLivraison(ZoneHabitation zone) const
{
	return fraisLivraison_[static_cast<int>(zone)];
}

GestionnairePlats* Restaurant::getMenu(TypeMenu typeMenu) const
{
	switch (typeMenu) {
	case TypeMenu::Matin : return menuMatin_;
	case TypeMenu::Midi  : return menuMidi_;
	case TypeMenu::Soir  : return menuSoir_;
	}
	assert(false && "Le type du menu est invalide");
	return nullptr;  // On ne devrait jamais se rendre � cette ligne.
}

GestionnairePlats* Restaurant::menuActuel() const
{
	return getMenu(momentJournee_);
}

GestionnaireTables* Restaurant::getTables(int id) const
{
	return tables_;
}

void Restaurant::lireAdresses(const string& nomFichier)
{
	LectureFichierEnSections fichier{nomFichier};
	fichier.allerASection("-ADDRESSES");
	while (!fichier.estFinSection()) {
		int zone; double frais;
		fichier >> zone >> frais;
		fraisLivraison_[zone] = frais;
	}
}

double Restaurant::getChiffreAffaire() {
	return chiffreAffaire_;
}

string getNomTypeMenu(TypeMenu typeMenu)
{
	return string{nomsDesTypesDeMenu[static_cast<int>(typeMenu)]};
}
