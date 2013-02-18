/* Menu du TP 4 - Arbre n-aire et carte géographique */
#include<stdio.h>
#include<stdlib.h>

/* Cette fonction initialise l'arbre
v1 : en dur dans le programme
v2 : chargement à partir d'un fichier
*/
void init_pays(){
	
}

void afficher_regions()
{
	printf("Ce traitement n'est pas encore disponible\n");
}

void ajouter_ville(void)
{	
	printf("Ce traitement n'est pas encore disponible\n");
}

void modifier_nom(void)
{
	printf("Ce traitement n'est pas encore disponible\n");
}

void region_dept(void)
{
	printf("Ce traitement n'est pas encore disponible\n");
}

void nombre_dept(void)
{
	printf("Ce traitement n'est pas encore disponible\n");
}

void afficher_rec(int p)
/* Affiche recursivement les valeurs du sous-arbre courant */
{
}
	
void afficher_arbre()
/* Affiche toutes les valeurs de l'arbre dans l'ordre prefixe */
{	
}

/*
 * MENU
 */
// Affichage du menu
int menu(){
	// Affichage du menu 
	printf("\nMenu :\n");
	printf(" 0 - Afficher l'arbre\n");
	printf(" 1 - Afficher les regions\n");
	printf(" 2 - Ajouter une ville\n");
	printf(" 3 - Modifier le nom d'une zone\n");
	printf(" 4 - Donner la region d'un departement\n");
	printf(" 5 - Donner le nombre de departements\n");
	printf(" 6 - Quitter\n");
	printf("Votre choix : ");
	scanf("%i",&choix);
	return choix;
}

/*
 * PROGRAMME PRINCIPAL
 */
int main(void){	
	int choix; // Contient le choix de l'utilisateur
	init_arbre(); // Initialisation de l'arbre
	init_pays();
	do{
		switch(choix)
		{	case 0:  afficher_arbre(); break;
			case 1:  afficher_regions(); break;
			case 2:  ajouter_ville(); break;
			case 3:  modifier_nom(); break;
			case 4:  region_dept(); break;
			case 5:  nombre_dept(); break;
			case 6:  break;
			default: printf("Erreur: votre choix doit être compris entre 0 et 6\n");
		}
	}
	while(choix!=6);
	printf("Au revoir !\n");
	// END
	return EXIT_SUCCESS;
}
