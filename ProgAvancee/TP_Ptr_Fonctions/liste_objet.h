#ifndef _LISTE_OBJET_H_
#define _LISTE_OBJET_H_

#include <liste_sdd.h>

typedef struct liste_objet_s liste_objet_t;

struct liste_objet_s {
	err_t (*detruire)(liste_objet_t **);
	void (*afficher)(liste_objet_t * const, const char);
	int (*nb_lire)(liste_objet_t * const);
	objet_t * (*elem_lire)(liste_objet_t * const, const int);
	booleen_t (*vide)(liste_objet_t * const);
	err_t (*elem_ecrire)(liste_objet_t *, objet_t * const, const int); 
	liste_t (*creer)(const int);
	
	int nb;
	objet_t **liste;
};

extern unsigned long int liste_objet_cpt  ;

/*! Teste si la liste existe */
extern booleen_t liste_objet_existe( liste_objet_t * const liste) ;

/*!
 * Creation d'une liste 
 */
extern liste_objet_t * liste_objet_creer( const int nb);

#endif
