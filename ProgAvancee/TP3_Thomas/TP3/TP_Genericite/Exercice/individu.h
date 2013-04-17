#ifndef _INDIVIDU_H_
#define _INDIVIDU_H_

/*
 * DEFINITION OBJET "INDIVIDU"  
 */

#include <commun.h>

typedef struct individu_s 
{
  char * nom ;
  char * prenom ;
} individu_t ;

/*
 * VARIABLE LOCALE
 * declaration du compteur d'objets individu_t comme variable externe
 * pour compter les references sur ces objets 
 */

extern unsigned long int individu_cpt  ;

/* 
 * FONCTIONS
 */

extern individu_t * individu_creer(char * const prenom , char * const nom ) ;
extern booleen_t individu_existe( individu_t * const individu ) ;
extern err_t individu_detruire( individu_t ** individu ) ;
extern void individu_afficher( individu_t * const individu ) ;
extern int individu_comparer( const individu_t * const ind1 , const individu_t * const ind2 ) ;
#endif
