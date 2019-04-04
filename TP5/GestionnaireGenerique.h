/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Foncteur.h"

using namespace  std;

//              T   = pair<string, Plat*> ou Table*; 
//              C   = map<string, Plat*> ou set<Table*>; 
template<typename T, typename C>
class GestionnaireGenerique
{
public:
	C getConteneur() const;
	void ajouter(T t);

	int getNombreElements() const;

protected:
	C conteneur_;
};

template<typename T, typename C>
inline C GestionnaireGenerique<T,C>::getConteneur() const {
	return conteneur_;
}



template<typename T, typename C> //demande
inline void GestionnaireGenerique<T,C>::ajouter(T t) {
	conteneur_.insert(t);
}

template<typename T, typename C>
inline int GestionnaireGenerique<T,C>::getNombreElements() const {
	return conteneur_.size();
}