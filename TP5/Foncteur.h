/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;


class FoncteurPlatMoinsCher
{ 
public:
	bool operator()(pair<string, Plat*> pair1, pair<string, Plat*> pair2) {
		return pair1.second->getPrix() < pair2.second->getPrix();
	}
    
};

class FoncteurIntervalle
{
public:

	bool operator()(Plat plat) {
		return plat.getPrix() > borneInf_ && plat.getPrix() < borneSup_;

	}

private:
	int borneInf_;
	int borneSup_;
};

