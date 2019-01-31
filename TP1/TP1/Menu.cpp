/*
* Titre : Menu.cpp - Travail Pratique #1
* Date : 24 Janvier 2019
* Auteur : Sofia Alvarez
*
*
*/

#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Menu::Menu()
{

    capacite_ = MAXPLAT;
    nbPlats_= 0;
    type_ = Matin;

    for(int i =0; i < MAXPLAT; ++i){
    listePlats_[i] = new Plat();
    }

}

Menu::Menu(string fichier, TypeMenu type){
    type_ = type;

    lireMenu(fichier);
}



int Menu::getNbPlats() const {
    return nbPlats_;

}
 void Menu::afficher() const {
    cout << "Capacité: " << capacite_ << endl
         << "Nombre de plats: " << nbPlats_ << endl
         << "Type de menu: " ;
    switch(type_){
        case Matin:
            cout << "Matin " << endl
            break;
        case Midi:
            cout << "Midi " << endl;
            break;
        case Soir:
            cout << "Soir " << endl;
    }
    for (int i = 0; i < nbPlats_; ++i){
        cout << listePlats_[i] -> getNom() << ": "
             << "Coût: " << listePlats_[i] -> getCout() << " "
             << "Prix: " << listePlats_[i] -> getPrix() << endl;
    }
}

Plat* Menu::trouverPlat(string &nom) {
    for (int i = 0; i < nbPlats_; i++)
    {
        if (listePlats_[i] -> getNom() == nom)
        {
            return listePlats_[i];
        }
    }

    return nullptr;
}

void Menu::ajouterPlat(Plat &plat) {
    // faut verifier la capacite

     listePlats_[nbPlats_] = &plat;
}

void Menu::ajouterPlat(string &nom, double montant, double cout) {

  Plat* plat = new Plat(nom, montant, cout);

  listePlats_[nbPlats_] = plat;

}

bool Menu::lireMenu(string &fichier) {

    TypeMenu type;

    string menuLine, nom;
    double montant, cout;

    ifstream ficMenu;
    ficMenu.open(fichier);

    if(ficMenu.fail()){
        return false;
    }

    while(!ws(ficMenu).eof()) {
        getline(ficMenu,menuLine);

        if(menuLine == "-MATIN"){
            type = Matin;
        }
        if(menuLine == "-MIDI"){
            type = Midi;
        }
        if(menuLine == "-SOIR"){
            type = Soir;
        }
        while(type == type_){
            ficMenu >> nom >> montant >> cout;
            ajouterPlat(nom, montant, cout);
        }
    }

}
