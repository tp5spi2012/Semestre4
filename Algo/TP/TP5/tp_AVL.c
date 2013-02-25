/* Menu du TP 5 - Arbre AVL */
#include<stdio.h>
#include<stdlib.h>

/*
 * AFFICHER
 */
// Affiche les valeurs de l'arbre
void afficher(){
	if(!arbre_vide()){
		posit_rac();
		afficher_arbre_rec();
	}
	// END
}

/*
 * AFFICHER ARBRE REC
 */
// Affiche recursivement les valeurs de l'arbre
void afficher_arbre_rec(){
	int ec;
	if(filsg())
		posit_filsg();
		afficher_arbre_rec();
		posit_pere();
	}
	val_noeud(&ec);
	printf("%i\n",ec);
	if(filsd()){
		posit_filsd();
		afficher_arbre_rec();
		posit_pere();
	}
	// END
}

/*
 * ROTATION GAUCHE
 */
// Effectue une rotation a gauche
void rotation_gauche(){
	if(nc->gauche!=NULL) // Si nc possede un fils
		tmp = nc->gauche; // On enregistre la position du fils gauche du pere
	rotation_gauche_rec(nc, tmp);
	// TODO
	// END
}

/*
 * ROTATION GAUCHE REC
 */
// Effectue recursivement la rotation a gauche de l'arbre
void rotation_gauche_rec(){
	//TODO	
}

/*
 * ROTATION DROITE
 */
// Effectue la rotation a droite
void rotation_droite(){

}

void equilibrer(void)
{	
	printf("A reprendre d'un TP précédent\n");
}

void ajouter(void)
{
	printf("A reprendre d'un TP précédent\n");
}

void ajouter_equilibre(void)
{
	printf("Ce traitement n'est pas encore disponible\n");
}

/*
 * MENU
 */
// Affiche le menu
int menu(){
	int choix;
	/* Affichage du menu */
	printf("\nMenu :\n");
	printf(" 1 - Ajouter une valeur sans rééquilibrage\n");
	printf(" 2 - Ajouter une valeur\n");
	printf(" 3 - Rotation gauche\n");
	printf(" 4 - Rotation droite\n");
	printf(" 5 - Equilibrer l'arbre\n");
	printf(" 6 - Afficher l'arbre\n");
	printf(" 7 - Quitter\n");
	printf("Votre choix : ");
	scanf("%i",&choix);
	return choix;
}

/*
 * INIT TP5
 */
// Initialise le l'arbre pour le tp 5
void init_tp5(){
	init_arbre();
	ajout_filsg(1);
	ajout_filsg(2);
	posit_pere();
	ajout_filsd(3);
}

/* Programme principal */
int main(void)
{	
	int choix;	/* Choix de l'utilisateur */
	init_arbre(); // Initialisation de l'arbre
	do
	{
		/* Traitement du choix de l'utilisateur */
		switch(choix=menu())
		{	case 1:  ajouter(); break;
			case 2:  ajouter_equilibre(); break;
			case 3:  rotation_gauche(); break;
			case 4:  rotation_droite(); break;
			case 5:  equilibrer(); break;
			case 6:  afficher(); break;
			case 7:  break;
			default: printf("Erreur: votre choix doit être compris entre 1 et 7\n");
		}
	}
	while(choix!=7);
	printf("Au revoir !\n");
}
