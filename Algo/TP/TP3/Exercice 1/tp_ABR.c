// HUBA Thomas - Licence SPI - 2e annÈe - TP5
// TP n∞3 - Arbre Binaire de recherche

/*
 * LIB
 */

#include <stdio.h>
#include <stdlib.h>
#include "meo_ab_tp2.h"

/*
 * TOOLS
 */

typedef enum {false, true} bool;

/*
 * END
 */

// Primitives

/*
 * MAX
 */
// Retourne la valeur max de 2 entiers reÁus en paramËtre
int max(int a, int b){
	return a>b ? a:b;
}

/*
 * AFFICHER REC
 */
// Affichage de l'arbre par ordre rÈcursivement
void afficher_rec(){
	int i;
	if(filsg()){
		posit_filsg();
		afficher_rec();
		posit_pere();
	}
	val_noeud(&i);
	printf("%i ",i);
	if(filsd()){
		posit_filsd();
		afficher_rec();
		posit_pere();
	}
}

/*
 * AFFICHER
 */
// PrÈpare l'arbre pour l'affichage rÈcursif
void afficher(){
	if(!hors_arbre()){
		posit_rac();
		afficher_rec();
	}
}

/*
 * INIT TP3
 */
// Initialisa l'arbre pour le TP3
void init_tp3(){
	init_arbre();
	ajout_filsg(18);
	ajout_filsg(2);
	ajout_filsg(1);
	posit_pere();
	ajout_filsd(12);
	posit_pere();
	posit_pere();
	ajout_filsd(20);
}

/*
 * HAUTEUR REC
 */
// Parcours l'arbre et calcul rÈcursivement la hauteur de l'arbre
int hauteur_rec(int g, int d){
	if(filsg()){
		posit_filsg();
		printf("GAUCHE !\n");
		hauteur_rec(g+1,d);
		posit_pere();
	}
	if(filsd()){
		posit_filsd();
		printf("DROITE !\n");
		hauteur_rec(g,d+1);
		posit_pere();
	}
	return max(g,d);
}

/*
 * HAUTEUR
 */
// Affiche la hauteur de l'arbre
void hauteur(){
	if(!hors_arbre()){
		posit_rac();
		int val = hauteur_rec(1,0);
		printf("La hauteur de l'arbre est de %i.\n",val);
	}
}

/*
 * RECHERCHER REC
 */
// Recherche rÈcursivement la valeur reÁu en paramËtre dans l'arbre
bool rechercher_rec(int val){
	int tmp;
	val_noeud(&tmp);
	if(tmp==val)
		return true;
	if(filsg()){
		posit_filsg();
		rechercher_rec(val);
		posit_pere();
	}
	if(filsd()){
		posit_pere();
		rechercher_rec(val);
		posit_pere();
	}
	return false;
}

/*
 * RECHERCHER
 */
// Affiche la valeur trouvÈ, NULL sinon
void rechercher(void){
	int val;
	if(!hors_arbre()){
		posit_rac();
		printf("Enter value : ");
		scanf("%i",&val);
		if(rechercher_rec(val))
			printf("TrouvÈ ! (%i)\n",val);
		else
			printf("Pas trouvÈ !\n");
	}
}

void ajouter(void)
{
	printf("Ce traitement n'est pas encore disponible\n");
}

/*
 * MENU
 */
// Affiche le menu
int menu(){
		int choix;
		printf("\nMenu :\n");
		printf(" 1 - Afficher les valeurs par ordre croissant\n");
        	printf(" 2 - Afficher la hauteur de l'arbre\n");
		printf(" 3 - Ajouter une valeur\n");
		printf(" 4 - Chercher une valeur et ses ancêtres\n");
		printf(" 5 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i",&choix);
		// END
		return choix;

}

/*
 * PROGRAMME PRINCIPAL
 */
int main(void){	
	int choix; // Choix de l'utilisateur
	init_tp3(); // Initialisation pour le TP3
	do{	
		switch(choix=menu()){
			case 1: // Affichage
				afficher();
				break;
			case 2: // Hauteur 
				hauteur();
				break;
			case 3:  ajouter(); break;
				
			case 4: // Rechercher
				rechercher();
				break;

			case 5:  break;
			default: printf("Erreur: votre choix doit être compris entre 1 et 5\n");
		}
	}while(choix!=5);
	printf("Au revoir !\n");
	// END
	return EXIT_SUCCESS;
}
