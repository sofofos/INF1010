/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#ifndef CLIENT_OCCASIONNEL
#define CLIENT_OCCASIONNEL

#include "Client.h"

class ClientOccasionnel: public Client
{
public:
	ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe);
     virtual int getNbPoints() const;// TODO done 
     virtual void afficherClient(ostream & os) const;// TODO done
     virtual double getReduction(const Restaurant & res, double montant, bool estLivraison); // TODO done
};

#endif
