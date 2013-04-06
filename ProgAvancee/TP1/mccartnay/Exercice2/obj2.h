#ifndef _OBJ2_H_
#define _OBJ2_H_

#include <commun.h>
#include <obj1s.h>

/*
 * DEFINITION OBJET 1 
 */

typedef struct obj2_s 
{
  obj1s_t * liste_objets ;
  char * attributs ;
} obj2_t ;

/*
 * VARIABLE LOCALE
 */



/* 
 * FONCTIONS
 */

extern obj2_t * obj2_creer(const int nb_obj1) ;
extern err_t obj2_detruire( obj2_t ** obj2 ) ;
extern booleen_t obj2_existe( obj2_t * const obj2 ) ;
extern err_t obj2_copier( obj2_t ** obj2_cible , obj2_t * const obj2_source ) ;
extern void obj2_afficher( obj2_t * const obj2 )  ;
#endif
