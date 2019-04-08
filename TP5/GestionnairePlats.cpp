/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#include "GestionnairePlats.h"
#include "LectureFichierEnSections.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"


GestionnairePlats::GestionnairePlats(const string& nomFichier, TypeMenu type)
	:type_(type)
{
	lirePlats(nomFichier, type);
}

GestionnairePlats::GestionnairePlats(GestionnairePlats* gestionnaire) { //TODO
	
}

GestionnairePlats::~GestionnairePlats() {// TODO

}

TypeMenu GestionnairePlats::getType() const {
	return type_;
}

Plat* GestionnairePlats::allouerPlat(Plat* plat) {
	Plat* unPlat = new Plat(*plat);
	return unPlat;
}

Plat* GestionnairePlats::trouverPlatMoinsCher() const {
	return (min_element(conteneur_.begin(), conteneur_.end(), FoncteurPlatMoinsCher()))->second;

}

Plat* GestionnairePlats::trouverPlatPlusCher() const { //TODO

	auto p = [](pair<string, Plat*> pair1, pair<string, Plat*> pair2) { //a confirmer
		return pair1.second->getPrix() < pair2.second->getPrix();
	};

	return (max_element(conteneur_.begin(), conteneur_.end(), p() ))->second;
}

Plat* GestionnairePlats::trouverPlat(const string& nom) const {
	return (find(conteneur_.begin(), conteneur_.end(), nom))->second;
}

vector<pair<string, Plat*>> GestionnairePlats::getPlatsEntre(double borneInf, double borneSup) {
	map<string, Plat*>::iterator itrBegin = conteneur_.begin();
	map<string, Plat*>::iterator itrEnd = conteneur_.begin();
	
	for (int i = 0; i < borneInf; i++)
		itrBegin++;
	for (int i = 0; i < borneSup; i++)
		itrEnd++;

	vector<pair<string, Plat*>> vecteurSortie;
	copy(itrBegin, itrEnd, vecteurSortie);

	return vecteurSortie;

}

void GestionnairePlats::lirePlats(const string& nomFichier, TypeMenu type)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type)]);
	while (!fichier.estFinSection())
		ajouter(lirePlatDe(fichier));
}

pair<string, Plat*> GestionnairePlats::lirePlatDe(LectureFichierEnSections& fichier)
{
	auto lectureLigne = fichier.lecteurDeLigne();
	Plat* plat;
	string nom, typeStr;
	TypePlat type;
	double prix, coutDeRevient;
	lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
	type = TypePlat(stoi(typeStr));
	double ecotaxe, vitamines, proteines, mineraux;
	switch (type) {
	case TypePlat::Bio:
		lectureLigne >> ecotaxe;
		plat = new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
		break;
	case TypePlat::BioVege:
		lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
		plat = new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
		break;
	case TypePlat::Vege:
		lectureLigne >> vitamines >> proteines >> mineraux;
		plat = new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
		break;
	default:
		plat = new Plat{ nom, prix, coutDeRevient };
	}
	return pair<string, Plat*>(plat->getNom(), plat);
}

void GestionnairePlats::afficherPlats(ostream& os) {
	map<string, Plat*>::iterator itr = conteneur_.begin();
	for (itr; itr != conteneur_.end(); itr++)
		(itr->second)->afficherPlat(os);
	
}
