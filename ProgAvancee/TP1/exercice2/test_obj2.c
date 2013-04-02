#include <stdio.h>
#include <obj2.h>

#define N 10 

int
main() 
{
  err_t noerr = OK; 
  obj2_t * o1 = NULL ; 
  obj2_t * o2 = NULL ; 

  printf( "Debut du programme des test sur les objets de type obj2_t\n" ) ; 

  printf( "Test d'existance sur un obj2_t inexistant\n" ) ;
  ( obj2_existe(o1) ? printf("-->KO\n") : printf ("-->OK\n") )  ;

  printf( "Test creation obj2_t\n" ) ;
  if( ( o1 = obj2_creer(N) ) == NULL ) 
    {
      printf("Debordement memoire\n" ) ;
      return(ERR_DEB_MEMOIRE) ; 
    }

  printf( "Test affichage o1\n" ) ;
  obj2_afficher( o1 ) ; 
  printf( "\n");

  printf( "Test d'existance sur un obj2_t existant\n" ) ;
  ( obj2_existe(o1) ? printf("-->OK\n") : printf ("-->KO\n") )  ;
  
  printf( "Test copie de: o2 <-- o1\n" ) ;
  if( ( noerr = obj2_copier( &o2 , o1 ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  
  printf( "Test affichage o2\n" ) ;
  obj2_afficher( o2 ) ; 
  printf( "\n"); 
  
  printf( "Test destruction o1\n" ) ;
  if( ( noerr = obj2_detruire( &o1 ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }

  printf( "Test destruction o2\n" ) ;
  if( ( noerr = obj2_detruire( &o2 ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  
  printf( "Fin du programme des test sur les objets de type obj2_t\n" ) ; 

  return(0) ; 
}
