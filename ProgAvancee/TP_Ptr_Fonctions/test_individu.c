#include <stdio.h>
#include <individu.h>

int
main() 
{
  /* err_t noerr = OK; */
  individu_t * indiv_1 = NULL ; 

  printf( "Debut du programme des test sur les objets de type individu_t\n" ) ; 

  printf( "Test d'existance sur un individu_t inexistant\n" ) ;
  ( individu_existe(indiv_1) ? printf("-->KO\n") : printf ("-->OK\n") )  ;

  printf( "Test creation individu_t\n" ) ;
  indiv_1 = individu_creer( "Roger" , "Waters" ) ;

  printf( "Test affichage indiv_1\n" ) ;  
  indiv_1->afficher(indiv_1);
  printf( "\n");

  printf( "Test d'existance sur un individu_t existant\n" ) ;
  ( individu_existe(indiv_1) ? printf("-->OK\n") : printf ("-->KO\n") )  ;
  
  printf( "Test destruction indiv_1\n" ) ;
  indiv_1->detruire(&indiv_1);
  
  printf( "Fin du programme des test sur les objets de type individu_t\n" ) ; 
  
  printf( "Nombre de individu_t  = %lu\n" , individu_cpt ) ;

  return(0) ; 
}
