#include <stdlib.h>
#include <string.h>
#include <mystring.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int string_cpt = 0 ; 

/* 
 * FONCTIONS
 */

extern 
booleen_t string_existe( string_t * const string )
{
  if( string == NULL ) 
    return(FAUX) ;
  else
    return(VRAI) ; 
}

static err_t string_detruire( string_t ** string ) {
	free((*string) -> string);
	(*string) -> afficher = NULL;
	(*string) -> detruire = NULL;
	free(string);
	(*string) = NULL;
	string_cpt--;
	return OK;
}

static
void string_afficher( string_t * const string ) 
{

  printf( "{" ) ; 
  if(  string_existe(string) ) 
    {
      printf( "%s" , string->string) ;
    }
  printf( "}" ) ; 
}

extern string_t * string_creer( char * const chaine ) {
	string_t * string = NULL;
	string = malloc((strlen(chaine) + 1) * sizeof(char));
	strcpy(string -> string, chaine);
	string -> afficher = void (objet_t*)string_afficher;
	string -> detruire = err_t (objet_t*)string_detruire;
	string_cpt++;
	return string;
}
