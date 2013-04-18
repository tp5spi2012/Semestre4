#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <commun.h>

/*
 * DEFINITION OBJET "STRING"  
 */

typedef struct string_s 
{
  char * string ;
} string_t ;

/*
 * VARIABLE LOCALE
 * declaration du compteur d'objets string_t comme variable externe
 * pour compter les references sur ces objets 
 */

extern unsigned long int string_cpt  ;

/* 
 * FONCTIONS
 */

extern string_t * string_creer(char * const chaine ) ;
extern booleen_t string_existe( string_t * const string ) ;
extern err_t string_detruire( string_t ** string ) ;
extern void string_afficher( string_t * const string ) ;
extern int string_comparer( const string_t * const str1 , const string_t * const str2 ) ;
#endif
