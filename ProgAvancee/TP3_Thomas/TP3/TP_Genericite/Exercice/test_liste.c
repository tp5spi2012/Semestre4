#include <stdio.h>
#include <stdlib.h>

#include <individu.h>
#include <fraction.h>
#include <mystring.h>
#include <liste.h>

/* 
 * On inclue la librairie qui contient les outils nécessaire
 * pour la récupération des arguments
 */

#include <unistd.h>

/*
 * Variable nécéssaire à getopt
 */

extern char *optarg;
extern int optind;
extern int optopt;
extern int opterr;
extern int optreset;

// #define N 5 // On place la valeur de N en paramètre 

int main(int argc, char * argv[]){
  err_t noerr = OK; 
  
  /*
   * Définition des flag
   */
  
  int nflag=0;
  int vflag=0;

  int nvalue = NULL;

  /*
   * Définition variable pour le parcours des options
   */
  
  


  while((getopt(argc,) != -1)
  

  individu_t ** individus = NULL  ; 
  fraction_t ** fractions = NULL  ;
  string_t ** strings = NULL  ; 

  liste_t * liste = NULL ; 
  int i = 0 ; 
 
  individus = malloc( sizeof(individu_t *) * N )  ; 
  fractions = malloc( sizeof(fraction_t *) * N )  ;
  strings = malloc( sizeof(string_t *) * N )   ; 

  printf( "Debut du programme des test sur les listes de %d objets homogenes\n" , N ) ; 

  printf( "\nTest creation d'une liste de %d individus \n" , N ) ;
  char prenom[128] ;
  char nom[128] ; 
  liste = liste_creer(N) ;  
  for( i=0 ; i<N ; i++ ) 
    {
      sprintf( nom , "nom_%d" , N-i ) ;
      sprintf( prenom , "prenom_%d" , N-i ) ;
      individus[i] = individu_creer( prenom , nom ) ; 
      liste_elem_ecrire( liste , individus[i] , i ) ;
    }

  printf( "Test affichage liste d'individus AVANT tri \n" ) ;
  liste_afficher( liste , ' ' ) ; 
  printf( "\n");

  printf( "Test Tri de la liste des individus\n" );
  liste_trier( liste  ) ;

  printf( "Test affichage liste d'individus APRES tri\n" ) ;
  liste_afficher( liste , ' ' ) ; 
  printf( "\n");
 
  printf( "Test destruction liste d'individus\n" ) ;
  if( ( noerr = liste_detruire( &liste ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }

  printf( "\nTest creation d'une liste de %d fractions \n" , N ) ;
  liste = liste_creer(N) ;  
  for( i=0 ; i<N ; i++ ) 
    {
      fractions[i] = fraction_creer( N-i , N-i+1 ) ; 
      liste_elem_ecrire( liste , fractions[i] , i ) ;
    }

  printf( "Test affichage liste de fractions AVANT tri\n" ) ;
  liste_afficher( liste , ' ' ) ; 
  printf( "\n");

  printf( "Test Tri de la liste des fractions\n" );
  liste_trier( liste ) ;

  printf( "Test affichage liste des fractions APRES tri\n" ) ;
  liste_afficher( liste ,  ' ' ) ; 
  printf( "\n");
 
  printf( "Test destruction liste de fractions\n" ) ;
  if( ( noerr = liste_detruire( &liste ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  

  printf( "\nTest creation d'une liste de %d strings \n" , N ) ;
  char string[128] ;
  liste = liste_creer(N) ;  
  for( i=0 ; i<N ; i++ ) 
    {
      sprintf( string , "string_%d" , N-i ) ; 
      strings[i] = string_creer( string ) ; 
      liste_elem_ecrire( liste , strings[i] , i ) ;
    }

  printf( "Test affichage liste de strings AVANT tri\n" ) ;
  liste_afficher( liste ,  ' ' ) ; 
  printf( "\n");
 
  printf( "Test Tri de la liste des strings\n" );
  liste_trier( liste  ) ;
  
  printf( "Test affichage liste des strings APRES tri\n" ) ;
  liste_afficher( liste ,  ' ' ) ; 
  printf( "\n");
  
  printf( "Test destruction liste de strings\n" ) ;
  if( ( noerr = liste_detruire( &liste  ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }

  free( individus ) ;
  free( fractions ) ;
  free( strings ) ; 

  printf( "\nFin du programme des test sur la lste d'objets homogenes\n" ) ; 
  
  printf( "Nombre de liste_t  = %lu\n" , liste_cpt ) ;

  return(0) ; 
}
