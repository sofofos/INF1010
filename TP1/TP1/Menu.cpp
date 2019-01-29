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
    for (int i = 0; i < MAXPLAT; i++)
    {
        listePlats.push_back(new Plat());
    }

}

Menu::Menu(string fichier, TypeMenu type){
    type_ = type;

    string strMenu;

    ifstream ficMenu;
    ficMenu.open(fichier);

    while(!ws(ficMenu).eof()){
        getline(ficMenu,strMenu);

        if(strMenu[0] == '-'){
            strMenu = strMenu.substr(1);
            //if(strMenu == 'MATIN'){}
        }
        // switch (TypeMenu) {
        //     case 'Matin': cout << "   ";
        //     case 'Midi' : cout << "   ";
        //     case 'Soir' : cout << "   ";
        // }
    }
}


}

int Menu::getNbPlats() const {
    return nbPlats_;

}
 void Menu::afficher() const {
    cout << "Voici son menu " << endl;


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
    //if(nbPlats_ < capacite_){ // faut-il verifier la capacite? a confirmer
        listePlats_[nbPlats_] = &plat; //dereferencement
   // }else{}

    // listePlats_.pushback(&plat); // verifier si on peut utiliser pushback
}

void Menu::ajouterPlat(string &nom, double montant, double cout) {
  //  listePlats_.push_back(new Plat(nom,montant,cout));
  Plat* plat = new Plat(nom, montant, cout);

  listePlats_[nbPlats_] = plat;

}

bool Menu::lireMenu(string &fichier) {
    TypeMenu type;

    string menuLine;

    ifstream ficMenu;
    ficMenu.open(fichier);

    while(!ws(ficMenu).eof()){
        getline(ficMenu,menuLine);

        // ajouter un while pour dire "lire jusqua trouver le type desiree et ensuite un autre while pour lire le reste du menu
        if(menuLine == "-MATIN"){
            type = Matin;
        }
        if(menuLine == "-MIDI"){
            type = Midi;
        } if(menuLine == "-SOIR"){
            type = Soir;
        }
        if(type == type_){ // ajouter un while
            getline(ficMenu,menuLine){ // optimiser la comparaison de type
                // lire et storer chaque mot dans la variable approprie, et utiliser la methode ajouterPlat qui prends nom, montant cout en parametre
            }
        }


//        if(menuLine[0] == '-'){
//            menuLine = menuLine.substr(1); // lire doit storer dans listePlats
//        }


    }
}
