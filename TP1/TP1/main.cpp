/*
* Titre : main.cpp - Travail Pratique #1
* Date : 24 Janvier 2019
* Auteur : Sofia Alvarez (1894026) & Justin de Meulemeester(1897007)
*/

#include "Restaurant.h"

int main() {


	//creation du restaurant - avec le fichier donne - le nom : PolyFood - moment de la journee : soir. 

	//Initialisation des strings pour ne pas passer des tableaux de char en param�tre.
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

	//Initialiser les strings pour ne pas passer des tableaux de char en param�tre
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
/* R�PONSES AUX QUESTIONS :

1- Le lien entre les classes Menu et Plat est une AGR�GATION. En effet, lorsqu'un objet de Menu est
d�truit, l'objet de Plat qui est inclus dans l'objet de menu n'est pas d�truit. L'agr�gation a
�t� impl�ment� par pointeurs (un des attributs de menu est un tableau de pointeurs).

2- Une m�thode ayant un const sera d�sormais une m�thode constante et ne pourra effectuer aucune
modification sur les attributs de l'objet. De plus, le compilateur n'acceptera pas qu'une m�thode
constante utilise une m�thode qui n'a pas �t� d�clar�e consante.

(R�f�rence: notes de cours)
*/



