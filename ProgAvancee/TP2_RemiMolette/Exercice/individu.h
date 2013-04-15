#ifndef _INDIVIDU_H_
#define _INDIVIDU_H_

#include <objet.h>


/*
 * DEFINITION OBJET "INDIVIDU"  
 */

typedef struct individu_s individu_t;

struct individu_s 
{
  #include <attributs_objet.h>
  char * nom ;
  char * prenom ;
  /* void (*afficher)(individu_t *);
  err_t (*detruire)(individu_t **); */ 
};

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

#endif
