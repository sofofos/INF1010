#include "Commande.h"

/*
* Date : 3 avril 2019
* Auteur : Pierre-Olivier C�t�
*/

Commande::Commande() {

}
QStringList Commande::getCommande() {
	return commande_;
}
void Commande::ajouterPlat(QString nomPlat) {
    commande_.push_back(nomPlat);
    emit commandeModifie();
}

void Commande::retirerPlat(QString nomPlat) {
    if(commande_.removeOne(nomPlat)){
        emit commandeModifie();
    } //TODO
}

void Commande::viderCommande(){
    if(commande_.size() == 0){
        throw ErreurCommandeVide(LABEL_NO_MEAL);
    }
    commande_.clear();
    emit commandeModifie();
}
