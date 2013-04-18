#include <stdio.h>
#include <mystring.h>

int
main() 
{
  err_t noerr = OK; 
  string_t * string = NULL ; 
  string_t * string_2 = NULL ; 

  printf( "Debut du programme des test sur les objets de type string_t\n" ) ; 

  printf( "Test d'existance sur un string_t inexistant\n" ) ;
  ( string_existe(string) ? printf("-->KO\n") : printf ("-->OK\n") )  ;

  printf( "Test creation string_t\n" ) ;
  string = string_creer( "azertyuiop" ) ;

  printf( "Test affichage string\n" ) ;
  string_afficher( string ) ; 
  printf( "\n");

  printf( "Test d'existance sur un string_t existant\n" ) ;
  ( string_existe(string) ? printf("-->OK\n") : printf ("-->KO\n") )  ;
  

  printf( "Test comparaison string_t\n" ) ;
  string_2 = string_creer( "azertyuiopAAA" ) ;  
  int cmp = string_comparer( string , string_2 ) ;
  string_afficher( string ) ; 
  if( cmp < 0 ) printf( " < " ) ; 
  if( cmp == 0 ) printf( " == " ) ; 
  if( cmp > 0 ) printf( " > " ) ; 
  string_afficher(string_2 ) ; 
  printf("\n");
  
  cmp = string_comparer( string_2 , string ) ;
  string_afficher( string_2 ) ; 
  if( cmp < 0 ) printf( " < " ) ; 
  if( cmp == 0 ) printf( " == " ) ; 
  if( cmp > 0 ) printf( " > " ) ; 
  string_afficher(string ) ; 
  printf("\n");

  cmp = string_comparer( string_2 , string_2 ) ;
  string_afficher( string_2 ) ; 
  if( cmp < 0 ) printf( " < " ) ; 
  if( cmp == 0 ) printf( " == " ) ; 
  if( cmp > 0 ) printf( " > " ) ; 
  string_afficher(string_2 ) ; 
  printf("\n");

  printf( "Test destruction string\n" ) ;
  if( ( noerr = string_detruire( &string ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  if( ( noerr = string_detruire( &string_2 ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  
  printf( "Fin du programme des test sur les objets de type string_t\n" ) ; 
  
  printf( "Nombre de string_t  = %lu\n" , string_cpt ) ;

  return(0) ; 
}
