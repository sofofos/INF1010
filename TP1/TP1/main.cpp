/*
* Titre : main.cpp - Travail Pratique #1
* Date : 24 Janvier 2019
* Auteur : Sofia Alvarez (1894026) & Justin de Meulemeester(1897007)
*/

#include "Restaurant.h"

int main() {


	//creation du restaurant - avec le fichier donne - le nom : PolyFood - moment de la journee : soir. 

	//Initialisation des strings pour ne pas passer des tableaux de char en paramètre.
	string nomFichier = "polyFood.txt";
	string nomRestaurant = "PolyFood";

	Restaurant poly(nomFichier, nomRestaurant, Soir);

	//creer plusieurs clients -- des entiers 
	int client1 = 1;
	int client2 = 5;
	int client3 = 15;
	int client4 = 3;
	int client5 = 2;

	//placer les clients
	poly.placerClients(client1);
	poly.placerClients(client2);
	poly.placerClients(client3);
	poly.placerClients(client4);
	poly.placerClients(client5);

	//commander des plats

	//Initialiser les strings pour ne pas passer des tableaux de char en paramètre
	string poisson = "Poisson";
	string poulet = "Poulet";
	string pizza = "Pizza";
	string muffin = "Muffin";
	string oeuf = "Oeuf";


	//Poisson - Table 1 
	poly.commanderPlat(poisson, 1);
	//Poulet - Table 2
	poly.commanderPlat(poulet, 2);
	//Pizza - Table 2 
	poly.commanderPlat(pizza, 2);
	//Poulet - Table 4
	poly.commanderPlat(poulet, 4);
	//Muffin - Table 4 
	poly.commanderPlat(muffin, 4);
	//Oeuf - Table 4 
	poly.commanderPlat(oeuf, 4);

	//afficher le restaurant
	poly.afficher();

	cout << "-------------------------------------------------" << endl;

	//liberer les tables 
	poly.libererTable(1);
	poly.libererTable(2);
	poly.libererTable(3);
	poly.libererTable(4);

	//afficher le restaurant 
	poly.afficher();


	return 0;
}
/* RÉPONSES AUX QUESTIONS :

1- Le lien entre les classes Menu et Plat est une AGRÉGATION. En effet, lorsqu'un objet de Menu est
détruit, l'objet de Plat qui est inclus dans l'objet de menu n'est pas détruit. L'agrégation a
été implémenté par pointeurs (un des attributs de menu est un tableau de pointeurs).

2- Une méthode ayant un const sera désormais une méthode constante et ne pourra effectuer aucune
modification sur les attributs de l'objet. De plus, le compilateur n'acceptera pas qu'une méthode
constante utilise une méthode qui n'a pas été déclarée consante.

(Référence: notes de cours)
*/



