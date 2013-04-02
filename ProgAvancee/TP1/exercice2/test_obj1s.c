#include <stdio.h>
#include <obj1s.h>

#define N 10 
int
main()
{
  err_t noerr = OK ; 
  obj1_t * objet = NULL ; 
  obj1s_t * liste = NULL ; 
  obj1s_t * copie_liste = NULL ; 
  int i = 0 ; 

  printf( "Debut programme de test des listes d'objets obj1_t\n"); 

   

  printf( "Test existance sur liste inexistante\n");
  ( obj1s_existe( liste )  ? printf("-->KO\n") : printf("-->OK\n") ) ;

  liste = obj1s_creer(0);

  printf( "Test existance sur liste existante\n");
  ( obj1s_existe( liste )  ? printf("-->OK\n") : printf("-->KO\n") ) ;

  printf( "Test vide sur liste vide\n");
  ( obj1s_vide( liste )  ? printf("-->OK\n") : printf("-->KO\n") ) ;

  liste = obj1s_creer(N) ;
  for( i=0 ; i<N ; i++ ) 
    {
      objet = obj1_creer() ;
      if( ( noerr = obj1s_obj1_ecrire( liste, objet , i ) ) )
	{
	  printf( "Sortie avec code erreur %d\n" , noerr ) ;
	  return(noerr) ; 
	}
      obj1_detruire(&objet) ;
    }
  
  printf( "Test vide sur liste vide\n");
  ( obj1s_vide( liste )  ? printf("-->KO\n") : printf("-->OK\n") ) ;

  printf( "Test affichage d'une liste\n");
  obj1s_afficher( liste ) ; 

  printf( "Test copie de la liste\n");
  if( ( noerr = obj1s_copier( &copie_liste , liste ) ) )
    {
      printf( "Sortie avec code erreur %d\n" , noerr ) ;
      return(noerr) ; 
    }

  printf( "Affichage liste copiee\n");
  obj1s_afficher( copie_liste ) ; 

  printf( "Test destruction liste "); fflush(stdout) ; 
  if( ( noerr = obj1s_detruire( &liste ) ) )
    {
      printf( "Sortie avec code erreur %d\n" , noerr ) ;
	  return(noerr) ; 
    }
  printf("-->OK\n" ) ; 

  printf( "Fin programme de test des listes d'objets obj1_t\n"); 

  return(OK); 
}
