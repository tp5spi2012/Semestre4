// HUBA Thomas - Licence SPI - Semestre 4 - Parcours Informatique - TP 2 Algo

// Exercice 1

/*
 * Coder le jeu à 20. Chaque joueur doit entrer un chiffre
 * entre 1 & 3, le but est d'arriver à 20.
 * Il est interdit de dépasser 20, même pour le dernier
 * joueur.
 * Ici, le deuxième joueur est une IA.
 */

/*
 * LIB
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * GLOBAL VAR
 */

int tot=0; // Contient la valeur total du score

/*
 * END
 */

// Primitives

/*
 * MENU
 */
// Affiche le menu
void menu()
{
	printf("HUBA Thomas - Licence SPI - TP2 - Exercice 1\n");
	printf("Bienvenue au jeu à 20 !\n\n");
}

/*
 * J TOUR
 */
// Demande au joueur courant d'entrer un nombre entre 0 & 3
int j_tour()
{
	int val; // Contient la valeur entreé par le joueur
	if(tot+3>=20) // Si le joueur est à 17 ou +
	{
		printf("Enter value [1 - %i] : ", 20-tot);
		scanf("%i", &val);
		// Alors on attend que (val + tot) ne dépasse pas 20
		while(val+tot>20)
		{
			printf("Enter value [1 - %i] : ", 20-tot);
			scanf("%i", &val);
		}
	}
	// Sinon, traitement standart
	else
	{
		// On demande une valeur entre 1 & 3
		printf("Enter value [1 - 3] : ");
		scanf("%i", &val);
		// On vérifie que celle-ci ne dépasse pas 3
		while(val <= 0 || val > 3)
		{
			printf("Enter value [1 - 3] : ");
			scanf("%i", &val);
		}
	}
	printf("Joueur joue : %i \t", val);
	// END
	return val;
}

/*
 * PRG TOUR
 */
// Le programme joue un tour à l'aide de la fonction rand
int prg_tour()
{
	int val; // Contient le choix du prg
	if(tot+3>=20)
		val=20-tot; // Le pc place un nombre pour atteindre 20
	else if(tot>0 && tot<4)
		val=4-tot;
	else if(tot>4 && tot<8)
		val=8-tot;
	else if(tot>8 && tot<12)
		val=12-tot;
	else if(tot>12 && tot<16)
		val=16-tot;
		//val=(rand()%3)+1; // On génère un nombre aléatoire entre 1 & 3 (0 exclus)
	printf("IA joue     : %i \t", val);
	// END
	return val;
}

/*
 * PROGRAMME PRINCIPAL
 */
int main()
{
	// Préparation
	srand(time(NULL)); // On initialise le générateur de nb aléatoire
	tot=0; // Contient le résultat total
	// Affichage menu
	menu();
	// Programme
	do
	{
		tot=tot+j_tour();
		if(tot==20){
			printf("TOTAL = %i\t",tot);
			printf("Joueur à gagné !\n");
			break;
		}
		else{
			printf("TOTAL = %i\n",tot);
		}
		tot=tot+prg_tour();
		if(tot==20){
			printf("TOTAL = %i\t",tot);
			printf("IA à gagné !\n");
		}
		else{
			printf("TOTAL = %i\n",tot);
		}
	}while(tot!=20);
	// END
	return EXIT_SUCCESS;
}
