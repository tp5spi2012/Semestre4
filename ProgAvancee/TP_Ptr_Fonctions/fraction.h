#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <objet.h>


/*
 * DEFINITION OBJET "INDIVIDU"  
 */

typedef struct fraction_s 
{
  #include <attributs_objet.h>
  int numerateur ;
  int denominateur ;
} fraction_t ;

/*
 * VARIABLE LOCALE
 * declaration du compteur d'objets fraction_t comme variable externe
 * pour compter les references sur ces objets 
 */

extern unsigned long int fraction_cpt  ;

/* 
 * FONCTIONS
 */

extern fraction_t * fraction_creer(const int numerateur , const int denominateur ) ;
extern booleen_t fraction_existe( fraction_t * const fraction ) ;

#endif
