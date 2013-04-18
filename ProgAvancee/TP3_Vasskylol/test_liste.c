#include <stdio.h>
#include <stdlib.h>

#include <getopt.h>

#include <individu.h>
#include <fraction.h>
#include <mystring.h>
#include <liste.h>
 

/* long options array */

static struct option longopts[] = {
  {"verbose", no_argument, NULL, (int)'v'},
  {0, 0, 0, 0}
};

int
main(int argc, char* argv[]) 
{
  int opt;
  int verbose = 0;

  err_t noerr = OK; 

  individu_t ** individus = NULL  ; 
  fraction_t ** fractions = NULL  ;
  string_t ** strings = NULL  ; 

  liste_t * liste = NULL ; 
  int i = 0 ;
  int n; 
 
  while((opt = getopt_long(argc, argv, "v", longopts, NULL)) != -1) {
    switch(opt) {
      case 'v': /* --verbose */
	verbose = 1;
 	break;
    }
  }

  argc -= optind; 
  argv += optind; 
	
  n = atoi(argv[0]);

  individus = malloc( sizeof(individu_t *) * n )  ; 
  fractions = malloc( sizeof(fraction_t *) * n )  ;
  strings = malloc( sizeof(string_t *) * n )   ; 

  if(verbose) printf( "Debut du programme des test sur les listes de %d objets homogenes\n" , n ) ; 

  if(verbose) printf( "\nTest creation d'une liste de %d individus \n" , n ) ;
  char prenom[128] ;
  char nom[128] ; 
  liste = liste_creer(n) ;  
  for( i=0 ; i<n ; i++ ) 
    {
      sprintf( nom , "nom_%d" , n-i ) ;
      sprintf( prenom , "prenom_%d" , n-i ) ;
      individus[i] = individu_creer( prenom , nom ) ; 
      liste_elem_ecrire( liste , individus[i] , i ) ;
    }

  if(verbose) printf( "Test affichage liste d'individus AVANT tri \n" ) ;
  liste_afficher( liste , 1, individu_afficher ) ; 
  printf( "\n");

  if(verbose) printf( "Test Tri de la liste des individus\n" );
  liste_trier( liste  ) ;

  if(verbose) printf( "Test affichage liste d'individus APRES tri\n" ) ;
  liste_afficher( liste , 1, individu_afficher ) ; 
  printf( "\n");
 
  if(verbose) printf( "Test destruction liste d'individus\n" ) ;
  if( ( noerr = liste_detruire( &liste, individu_detruire, NULL ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }

  if(verbose) printf( "\nTest creation d'une liste de %d fractions \n" , n ) ;
  liste = liste_creer(n) ;  
  for( i=0 ; i<n ; i++ ) 
    {
      fractions[i] = fraction_creer( n-i , n-i+1 ) ; 
      liste_elem_ecrire( liste , fractions[i] , i ) ;
    }

  if(verbose) printf( "Test affichage liste de fractions AVANT tri\n" ) ;
  liste_afficher( liste , 1, fraction_afficher ) ; 
  printf( "\n");

  if(verbose) printf( "Test Tri de la liste des fractions\n" );
  liste_trier( liste ) ;

  if(verbose) printf( "Test affichage liste des fractions APRES tri\n" ) ;
  liste_afficher( liste , 1, fraction_afficher ) ; 
  printf( "\n");
 
  if(verbose) printf( "Test destruction liste de fractions\n" ) ;
  if( ( noerr = liste_detruire( &liste, fraction_detruire, NULL ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }
  

  if(verbose) printf( "\nTest creation d'une liste de %d strings \n" , n ) ;
  char string[128] ;
  liste = liste_creer(n) ;  
  for( i=0 ; i<n ; i++ ) 
    {
      sprintf( string , "string_%d" , n-i ) ; 
      strings[i] = string_creer( string ) ; 
      liste_elem_ecrire( liste , strings[i] , i ) ;
    }

  if(verbose) printf( "Test affichage liste de strings AVANT tri\n" ) ;
  liste_afficher( liste , 1, string_afficher) ; 
  printf( "\n");
 
  if(verbose) printf( "Test Tri de la liste des strings\n" );
  liste_trier( liste  ) ;
  
  if(verbose) printf( "Test affichage liste des strings APRES tri\n" ) ;
  liste_afficher( liste , 1, string_afficher ) ; 
  printf( "\n");
  
  if(verbose) printf( "Test destruction liste de strings\n" ) ;
  if( ( noerr = liste_detruire( &liste, string_detruire, NULL ) ) )
    { 
      printf("Sortie avec code erreur = %d\n" , noerr ) ;
      return(noerr) ; 
    }

  free( individus ) ;
  free( fractions ) ;
  free( strings ) ; 

  if(verbose) printf( "\nFin du programme des test sur la lste d'objets homogenes\n" ) ; 
  
  printf( "Nombre de liste_t  = %lu\n" , liste_cpt ) ;

  return(0) ; 
}
