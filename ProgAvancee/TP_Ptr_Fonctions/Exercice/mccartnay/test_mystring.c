#include <stdio.h>
#include <mystring.h>

int
main() 
{
  /* err_t noerr = OK; */
  string_t * chaine = NULL ; 

  printf( "Debut du programme des test sur les objets de type string_t\n" ) ; 

  printf( "Test d'existance sur un string_t inexistant\n" ) ;
  ( string_existe(chaine) ? printf("-->KO\n") : printf ("-->OK\n") )  ;

  printf( "Test creation string_t\n" ) ;
  chaine = string_creer( "azertyuiop" ) ;

  printf( "Test affichage chaine\n" ) ;
  printf("\n***********\n* A FAIRE *\n***********\n");
  printf( "\n");

  printf( "Test d'existance sur un string_t existant\n" ) ;
  ( string_existe(chaine) ? printf("-->OK\n") : printf ("-->KO\n") )  ;
  
  printf( "Test destruction chaine\n" ) ;
  printf("\n***********\n* A FAIRE *\n***********\n");  
  printf( "Fin du programme des test sur les objets de type string_t\n" ) ; 
  
  printf( "Nombre de string_t  = %lu\n" , string_cpt ) ;

  return(0) ; 
}
