/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/
#ifndef PLAT_VEGE_H
#define PLAT_VEGE_H

#include "Vege.h"
#include "Plat.h"
#include "def.h"
class PlatVege :
        public Vege, public Plat
{
public:
	PlatVege(string nom = "inconnu", double prix = 0, double cout = 0, double vitamines = 0,
             double proteines = 0, double mineraux = 0);//TODO
     ~ PlatVege();
     Plat * clone()const; // TODO
     void afficherPlat(ostream & os) const;//TODO
     double calculerApportNutritif() const; // TODO
protected:

};
#endif
