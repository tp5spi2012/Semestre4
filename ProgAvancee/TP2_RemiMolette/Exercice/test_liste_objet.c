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

  /* liste_t * liste = NULL ; */

  printf( "Debut du programme des test sur les objets de type liste_t\n" ) ; 

  printf("\n***********\n* A FAIRE *\n***********\n");

  printf( "Fin du programme des test sur les objets de type liste_t\n" ) ; 
  
  return(0) ; 
}
