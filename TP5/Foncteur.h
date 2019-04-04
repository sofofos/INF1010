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
	bool operator()(Plat plat1, Plat plat2) {
		return plat1.getPrix() < plat2.getPrix;
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

