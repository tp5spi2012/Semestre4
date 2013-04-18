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

extern
err_t string_detruire( string_t ** string ) 
{

  /* Liberation attributs */
  free( (*string)->string ) ; 
  /* Liberation memoire de l'objet */
  free( (*string) ) ;
  /* Pour eviter les pointeurs fous */
  (*string) = NULL ; 

  string_cpt-- ; 

  return(OK) ; 
}

extern
void string_afficher( string_t * const string ) 
{

  printf( "{" ) ; 
  if(  string_existe(string) ) 
    {
      printf( "%s" , string->string) ;
    }
  printf( "}" ) ; 
}

extern 
string_t * string_creer( char * const chaine ) 
{
  string_t * string = NULL ; 

  /* Creation place memoire objet string */
  if( ( string = malloc(sizeof(string_t)) ) == NULL )
    {
      fprintf( stderr , "string_creer: debordement memoire lors de la creation d'un objet de type string_t (%lu demandes)\n", 
	       (unsigned long int)sizeof(string_t) ) ;
      return((string_t *)NULL);
    }

  /* Affectation attributs specifiques */
  if( ( string->string = malloc(sizeof(char)*strlen(chaine)+1) ) == NULL )
    {
      fprintf( stderr , "string_creer: debordement memoire lors de la creation d'un objet de type string_t (%lu demandes)\n", 
	       (unsigned long int)strlen(chaine)+1 ) ;
      return((string_t *)NULL);
    }
  strcpy( string->string , chaine ) ;

  string_cpt++ ; 

  return( string ) ;
}

extern
int string_comparer( const string_t * const str1 , const string_t * const str2 )
{
  return(strcmp( str1->string , str2->string) ) ;
}
