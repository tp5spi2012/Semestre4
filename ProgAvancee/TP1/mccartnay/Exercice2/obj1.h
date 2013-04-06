#ifndef _OBJ1_H_
#define _OBJ1_H_

#include <commun.h>

/*
 * DEFINITION OBJET 1 
 */

typedef struct obj1_s 
{
  char * attributs ;
} obj1_t ;

/*
 * VARIABLE LOCALE
 */



/* 
 * FONCTIONS
 */

extern obj1_t * obj1_creer() ;
extern err_t obj1_detruire( obj1_t ** obj1 ) ;
extern booleen_t obj1_existe( obj1_t * const obj1 ) ;
extern err_t obj1_copier( obj1_t ** obj1_cible , obj1_t * const obj1_source ) ;
extern void obj1_afficher( obj1_t * const obj1 )  ;
#endif
