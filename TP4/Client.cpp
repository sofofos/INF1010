/*********************************************************************
* Date : 25 février 2019
* Auteur : AbdeB
**********************************************************************
* Modifié par : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 21 Mars 2019
*********************************************************************/

#include "Client.h"

Client::Client()
{ tableOccupee_ = nullptr;
}

Client::Client(string_view nom, string_view prenom, int tailleGroupe) :
	nom_(nom), prenom_(prenom), tailleGroupe_(tailleGroupe)
{
    tableOccupee_ = nullptr;
}

int Client::getTailleGroupe() const
{
	return tailleGroupe_;
}

string Client::getNom() const 
{
	return nom_;
}

string Client::getPrenom() const
{
	return prenom_;
}

Table * Client::getTable() const
{
	return tableOccupee_;
}

void Client:: setTable(Table * ta)
{ 
	tableOccupee_ = ta;
}


void Client::afficherClient(ostream & os) const
{ // TODO done
	os << "Le client: " << prenom_ << " " << nom_;
	if (tableOccupee_ != nullptr) {
		os << "avec la table" << tableOccupee_ << endl;
	}
}


