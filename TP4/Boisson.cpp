/*********************************************************************
*  Boisson.cpp
*  Created by Martine Bellaiche on 2019-03-10.
*  Copyright © 2019 Martine Bellaiche. All rights reserved.
**********************************************************************
* Modifié par : Sofia Alvarez(1894026) & Justin de Meulemeester(1897007)
* Date: 21 Mars 2019
*********************************************************************/


#include "Boisson.h"

// TODO
Boisson::Boisson (string_view nom, double prix)
	: nom_(nom), prix_(prix)
{
	setTaxe();
}

double Boisson::getTaxe() const {
	return taxe_;
}

void Boisson::setTaxe(){
	taxe_ = 0.12;
}

string_view Boisson::getNom() const
{ return nom_;}
double Boisson::getPrix()  const
{return prix_;}
