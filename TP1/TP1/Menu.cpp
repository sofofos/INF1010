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
    ficMenu.open("polyFood.txt");

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
    for (int i = 0; i < listePlats.size(); i++)
    {
        if (listePlats.at(i) -> getNom() == nom)
        {
            return listePlats.at(i);
        }
    }

    Plat* plat = new Plat();
    return plat;
}

void Menu::ajouterPlat(Plat &plat) {
    listePlats.push_back(&plat);


}

void Menu::ajouterPlat(string &nom, double montant, double cout) {
    listePlats.push_back(new Plat(nom,montant,cout));

}

bool Menu::lireMenu(string &fichier) {

    string strMenu;

    ifstream ficMenu;
    ficMenu.open("polyFood.txt");

    while(!ws(ficMenu).eof()){
        getline(ficMenu,strMenu);

        if(strMenu[0] == '-'){
            strMenu = strMenu.substr(1); // lire doit storer dans listePlats
        }
    }
}
