/*
* Titre : Menu.cpp - Travail Pratique #1
* Date : 24 Janvier 2019
* Auteur : Sofia Alvarez (1894026) & Justin de Meulemeester(1897007)
*/

#include "Restaurant.h"
#include <string>

Restaurant::Restaurant() {
    *nom_ = "inconnu";
    momentJournee_ = Matin;
    chiffreAffaire_ = 0;

}

Restaurant::Restaurant(string &fichier, string &nom, TypeMenu moment) {



}

void Restaurant::setMoment(TypeMenu moment) {};

string Restaurant::getNom() {};

TypeMenu Restaurant::getMoment() {};

void Restaurant::lireTable(string &fichier) {};

void Restaurant::ajouterTable(int id, int nbPlaces) {};

void Restaurant::libererTable(int id) {};

void Restaurant::commanderPlat(string &nom, int idTable) {};

void Restaurant::placerClients(int nbClients) {};

void Restaurant::afficher() {};
