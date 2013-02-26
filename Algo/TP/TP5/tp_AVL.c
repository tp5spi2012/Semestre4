// NOM Prenom - Licence SPI - 2eme Année - TP5
// TP n°5

/*
 * LIB
 */

#include<stdio.h>
#include<stdlib.h>

/*
 * END
 */

// Primitives

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
// Effectue la rotation gauche simple dans un arbre AVL
void rotation_gauche(t_noeud * pivot){
	if(pivot->droit!=NULL){
		t_noeud * tmp = pivot->droit; // On enregistre le fils droit du pivot
		if(pivot!=racine){ // Si le pivot n'est pas la racine
			// On test donc si le pivot est un fils droit ou gauche
			if((pivot->pere)->droit = pivot) // Si fils droit
				(pivot->pere)->droit = tmp; // Alors le fils droit du pere du pivot devient tmp
			else	
				(pivot->pere)->gauche = tmp; // Sinon tmp devient fils gauche du pere du pivot
		}
		else racine = tmp; // Sinon tmp devient la racine
		// Mise à jour des chainages
		pivot->pere = tmp; // pivot devient le fils de tmp
		pivot->droit = tmp->gauche; // Le fils gauche de tmp devient le fils droit de pivot
		// Chainage du fils droit de pivot
		tmp->pere = pivot->pere; // le pere de pivot devient le pere de tmp
		tmp->gauche = pivot; // Pivot devient le fils gauche de tmp
		// Chainage du fils gauche du fils droit du pivot
		if(tmp->gauche!=NULL) // Si tmp possede un fils gauche
			(tmp->gauche)->pere = pivot; // Le pere du fils gauche de tmp devient pivot
	}
}

/*
 * ROTATION DROITE
 */
// Effectue la rotation a droite
void rotation_droite(t_noeud * pivot){
	if(pivot->gauche!=NULL){
		t_noeud * tmp = pivot->gauche; // On enregistre le fils droit du pivot
		if(pivot!=racine){ // Si le pivot n'est pas la racine
			// On test donc si le pivot est un fils droit ou gauche
			if((pivot->pere)->droit = pivot) // Si fils droit
				(pivot->pere)->droit = tmp; // Alors le fils droit du pere du pivot devient tmp
			else	
				(pivot->pere)->gauche = tmp; // Sinon tmp devient fils gauche du pere du pivot
		}
		else racine = tmp; // Sinon tmp devient la racine
		// Mise à jour des chainages
		pivot->pere = tmp; // pivot devient le fils de tmp
		pivot->gauche = tmp->droit; // Le fils droit de tmp devient le fils gauche de pivot
		// Chainage du fils droit de pivot
		tmp->pere = pivot->pere; // le pere de pivot devient le pere de tmp
		tmp->droit = pivot; // Pivot devient le fils droit de tmp
		// Chainage du fils droit du fils gauche du pivot
		if(tmp->droit!=NULL) // Si tmp possede un fils droit
			(tmp->droit)->pere = pivot; // Le pere du fils droit de tmp devient pivot
	}
}

void equilibrer(void){	
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
	ajout_filsg(1);
	posit_pere();
	ajout_filsd(4);
	// END
}

/*
 * PROGRAMME PRINCIPAL
 */
int main(void){	
	int choix;	/* Choix de l'utilisateur */
	init_arbre(); // Initialisation de l'arbre
	init_tp5(); // Initialise l'arbre pour le TP5
	do{
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
