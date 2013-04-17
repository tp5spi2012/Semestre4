#include <stdio.h>
#include <individu.h>
#include <fraction.h>
#include <mystring.h>
#include <liste_objet.h>

int
main() 
{
  err_t noerr = OK; 
  individu_t * indiv_1 = individu_creer( "Roger" , "Waters" ) ;
  individu_t * indiv_2 = individu_creer( "David" , "Gilmour" ) ; 
  fraction_t * frac_1 = fraction_creer( 3 , 5 ) ;
  fraction_t * frac_2 = fraction_creer( 9 , 13 ) ;
  string_t * str_1 = string_creer( "azertyuiop" ) ; 
  string_t * str_2 = string_creer( "qsdfghjklm" ) ;
  string_t * str_3 = string_creer( "wxcvbn" ) ; 

  liste_objet_t * liste = NULL ; 

  printf( "Debut du programme des test sur les objets de type liste_t\n" ) ; 

  printf( "Test d'existance sur une liste_t inexistant\n" ) ;
  ( liste_objet_existe(liste) ? printf("-->KO\n") : printf ("-->OK\n") )  ;

  printf( "Test creation liste_t\n" ) ;
  liste = liste_objet_creer(8) ;  
  liste->elem_ecrire( liste , (objet_t *)indiv_1 , 0 ) ;
  liste->elem_ecrire( liste , (objet_t *)frac_1  , 1 ) ;
  liste->elem_ecrire( liste , (objet_t *)str_1   , 2 ) ;
  liste->elem_ecrire( liste , (objet_t *)indiv_2 , 3 ) ;
  liste->elem_ecrire( liste , (objet_t *)frac_2  , 4 ) ;
  liste->elem_ecrire( liste , (objet_t *)str_2   , 5 ) ;
  liste->elem_ecrire( liste , (objet_t *)str_3   , 7 ) ;

  printf( "Test affichage liste \n" ) ;
  liste->afficher( liste , ' ' ) ; 
  printf( "\n");

  printf( "Test d'existance sur une liste_t existant\n" ) ;
  ( liste_objet_existe(liste) ? printf("-->OK\n") : printf ("-->KO\n") )  ;
  
  printf( "Test destruction liste\n" ) ;
  if( ( noerr = liste->detruire( &liste) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  
  printf( "Fin du programme des test sur les objets de type liste_t\n" ) ; 
  
  printf( "Nombre de liste_t  = %lu\n" , liste_objet_cpt ) ;

  return(0) ; 
}
