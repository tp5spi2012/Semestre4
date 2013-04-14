#include <stdlib.h>
#include <string.h>
#include <individu.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int individu_cpt = 0 ;

/*
 * FONCTIONS
 */

extern booleen_t individu_existe( individu_t * const individu ) {
	if( individu == NULL )
		return(FAUX) ;
	else
		return(VRAI) ;
}

static err_t individu_detruire( individu_t ** individu ) {
	free((*individu) -> nom);
	free((*individu) -> prenom);
	(*individu) -> afficher = NULL;
	(*individu) -> detruire = NULL;
	free(individu);
	(*individu) = NULL;
	individu_cpt++;
	return OK;
}

static err_t individu_detruire_cb (objet_t ** individu) {
	individu_detruire((individu_t **) individu);
}

static void individu_afficher( individu_t * const individu ) {
	printf( "{" ) ;
	if(  individu_existe(individu) ) {
		printf( "%s %s" , individu->prenom , individu->nom ) ;
	}
	printf( "}" ) ;
}

static void individu_afficher_cb (objet_t * individu) {
	individu_afficher((individu_t *) individu);
}

extern individu_t * individu_creer (char * const prenom, char * const nom) {
	individu_t * individu = NULL ;
	individu = malloc(sizeof(individu_t));
	individu -> nom = malloc((strlen(nom) + 1) * sizeof(char));
	strcpy(individu -> nom, nom);
	individu -> prenom = malloc((strlen(prenom) + 1) * sizeof(char));
	strcpy(individu -> prenom, prenom);
	individu -> afficher = malloc(sizeof(static void individu_afficher_cb()));
	individu -> afficher = static void (*individu_afficher_cb)(objet_t*);
	individu -> detruire = static err_t (*individu_detruire)(individu_t**);
	individu_cpt++;
	return individu;
}
