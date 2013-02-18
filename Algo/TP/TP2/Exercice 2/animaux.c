// HUBA Thomas - Licence SPI - 2e Année - Parcours Informatique - TP5
// TP2 - Exercice 2

/*
 * CONSIGNE TODO
 */

/*
 * LIB
 */

#include "meo_ab_tp2.h"

/*
 * PREDEF DATA
 */

#define TAILLE 500

/*
 * END
 */

// Primitives

/*
 * CHERCHER
 */
// Fonction qui recherche et positionne le noeud courant sur le noeud d'id id
int cherche(int id){
	int res=0;
	if(get_id() != id) {
		if(filsg()){
			posit_filsg();
			res = cherche(id);
			if(!res) // si on n'a pas trouvé, on remonte
				posit_pere();
		}
		if(filsd() && !res){ // si on n'a pas trouvé, on cherche à droite
			posit_filsd();
			res = cherche(id);
			if(!res)
				posit_pere();
		}
		return res;

	}
	// END
	return 1;
}

/*
 * AJOUT
 */
// Fonction qui se positionne sur le noeud d'id = pere et ajoute le fils gauche d'id id et de valeur q
int ajout(int pere, int id, char* q){
	posit_rac();
	int res = cherche(pere);
	if(res){
		if(!filsg())
			ajout_filsg(id, q);
		else if(!filsd())
			ajout_filsd(id, q);
		else {
			fprintf(stderr, "Le noeud %d a déjà un fg et un fd, problème dans le fichier !!\n", pere);
			res=0;
		}
	}
	else {
		fprintf(stderr, "Impossible d'ajouter %d, %s car le noeud d'id %d est introuvable !\n",id, q, pere);
	}
	// END
	return res;
}

/*
 * LOAD CLASSIFICATION
 */
// Charge le fichier contenant la classification arborescente
int loadClassification(char *fn){
	char line[TAILLE], q[TAILLE];
	int id, pere;
	FILE* fd = fopen(fn, "r");
	if (fd==NULL){ 
		perror ("Error opening file");
		return 0;
	}
	init_arbre();
	while(!feof(fd)){
		fgets(line, TAILLE, fd);
		sscanf(line, "%d %d %[^\n]", &id, &pere, q);
		if(!ajout(pere, id, q)) {
			exit(0);
		}
	
	}
	fclose(fd);
	// END
	return 1;
}

/*
 * GUESS
 */
// Devine l'animal auquel l'USER pense
void guess(){
	char * word=malloc(100*sizeof(char)); // Valeur du noeud
	char tmp; // Réponse de l'USER
	val_noeud(word);
	printf("%s ",word);
	if(!feuille()){
		scanf("%c",&tmp);
		if(tmp=='O'){ // Si +
			posit_filsg();
		}
		else if(tmp=='N'){ // Si -
			posit_filsd();
		}
		guess();
		free(word);
	}
	// END
}

int menu(){
	int choice;
	printf("HUBA Thomas - Licence SPI - Semestre 4\n");
	printf("TP2 - Exercice 2\n");
	printf("Bienvenue !\n");
	printf("1. Afficher la totalité de l'arbre\n");
	printf("2. Devine mon animal\n");
	printf("3. Quitter\n");
	printf(">> ");
	scanf("%i",&choice);
	return choice;
}

/*
 * AFFICHAGE
 */
// Affiche la totalité de l'arbre en fonction des réponses possible
void affichage(){
	char * word=malloc(100*sizeof(char));
	val_noeud(word);
	printf("%s\n",word);
	if(filsg()){
		printf("|___ ");
		posit_filsg();
		printf("[oui] ");
		affichage();
		printf("|___ ");
		posit_pere();
		printf("|___ ");
	}
	if(filsd()){
		printf("|___ ");
		posit_filsd();
		printf("[non] ");
		affichage();
		printf("|___ ");
		posit_pere();
		printf("|___ ");
	}
	free(word);
	// END
}

/*
 * PROGRAMME PRINCIPAL
 */
int main(int argc, char **argv){
	// Initialisation
	if(argc < 2){
		printf("Usage : %s <fic>\n", argv[0]);
		printf("fic doit contenir la classification sous forme d'arbre\n");
		exit(EXIT_SUCCESS);
	}
	char *fn = argv[1];
	loadClassification(fn);
	fprintf(stderr, "Classification chargée ...\n");
	// Menu
	int choice=menu();
	// Programme
	switch(choice){
		case 1:
			posit_rac();
			printf("[] ");
			affichage();
			printf("\n");
			break;
		case 2:
			posit_rac();
			guess();
			printf("\n");
		case 3:
			printf("Au revoir !\n");
			break;
		default:
			printf("Entrée inconnue !\n");
	}
	// END
	return EXIT_SUCCESS;
}
