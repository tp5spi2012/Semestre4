#include <stdio.h>
#include <obj1.h>

int
main() 
{
  err_t noerr = OK; 
  obj1_t * o1 = NULL ; 
  obj1_t * o2 = NULL ; 

  printf( "Debut du programme des test sur les objets de type obj1_t\n" ) ; 

  printf( "Test d'existance sur un obj1_t inexistant\n" ) ;
  ( obj1_existe(o1) ? printf("-->KO\n") : printf ("-->OK\n") )  ;

  printf( "Test creation obj1_t\n" ) ;
  o1 = obj1_creer() ;

  printf( "Test affichage o1\n" ) ;
   obj1_afficher( o1 ) ; 
   printf( "\n");

  printf( "Test d'existance sur un obj1_t existant\n" ) ;
  ( obj1_existe(o1) ? printf("-->OK\n") : printf ("-->KO\n") )  ;

  printf( "Test copie de: o2 <-- o1\n" ) ;
  if( ( noerr = obj1_copier( &o2 , o1 ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  
  printf( "Test affichage o2\n" ) ;
  obj1_afficher( o2 ) ; 
  printf( "\n"); 
  
  printf( "Test destruction o1\n" ) ;
  if( ( noerr = obj1_detruire( &o1 ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  
  printf( "Test destruction o2\n" ) ;
  if( ( noerr = obj1_detruire( &o2 ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  
  printf( "Fin du programme des test sur les objets de type obj1_t\n" ) ; 

  return(0) ; 
}
