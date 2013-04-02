#include <stdio.h>
#include <obj2s.h>

#define N1 5 
#define N2 10 
int
main()
{
  err_t noerr = OK ; 
  obj2_t * objet = NULL ; 
  obj2s_t * liste = NULL ; 
  obj2s_t * copie_liste = NULL ; 
  int i = 0 ; 

  printf( "Debut programme de test des listes d'objets obj2_t\n"); 

  printf( "Test existance sur liste inexistante\n");
  ( obj2s_existe( liste )  ? printf("-->KO\n") : printf("-->OK\n") ) ;

  liste = obj2s_creer(0);

  printf( "Test existance sur liste existante\n");
  ( obj2s_existe( liste )  ? printf("-->OK\n") : printf("-->KO\n") ) ;

  printf( "Test vide sur liste vide\n");
  ( obj2s_vide( liste )  ? printf("-->OK\n") : printf("-->KO\n") ) ;

  liste = obj2s_creer(N2) ;
  for( i=0 ; i<N2 ; i++ ) 
    {
      objet = obj2_creer(N1) ;
      if( ( noerr = obj2s_obj2_ecrire( liste, objet , i ) ) )
	{
	  printf( "Sortie avec code erreur %d\n" , noerr ) ;
	  return(noerr) ; 
	}
      obj2_detruire(&objet) ;
    }
  
  printf( "Test vide sur liste vide\n");
  ( obj2s_vide( liste )  ? printf("-->KO\n") : printf("-->OK\n") ) ;

  printf( "Test affichage d'une liste\n");
  obj2s_afficher( liste ) ; 

  printf( "Test copie de la liste\n");
  if( ( noerr = obj2s_copier( &copie_liste , liste ) ) )
    {
      printf( "Sortie avec code erreur %d\n" , noerr ) ;
      return(noerr) ; 
    }

  printf( "Affichage liste copiee\n");
  obj2s_afficher( copie_liste ) ; 

  printf( "Test destruction liste "); fflush(stdout) ; 
  if( ( noerr = obj2s_detruire( &liste ) ) )
    {
      printf( "Sortie avec code erreur %d\n" , noerr ) ;
	  return(noerr) ; 
    }
  printf("-->OK\n" ) ;

  printf( "Test destruction liste copiee"); fflush(stdout) ; 
  if( ( noerr = obj2s_detruire( &copie_liste ) ) )
    {
      printf( "Sortie avec code erreur %d\n" , noerr ) ;
	  return(noerr) ; 
    }
  printf("-->OK\n" ) ; 

  printf( "Fin programme de test des listes d'objets obj2_t\n"); 

  return(OK); 
}
