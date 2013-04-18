#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include <individu.h>
#include <fraction.h>
#include <mystring.h>
#include <liste.h>

/*#define N 5*/

static struct option longopts[] = {
	{"verbose", required_argument, NULL, (int)'v'},
	{0}
};

int main (int argc, char * argv[]) {
	if (argc < 2)
		printf("mauvais paramètres\n");
	else {
		int verbose = 0;
		int opt;
		while ((opt = getopt_long(argc, argv, "v", longopts, NULL)) != -1) {
				switch (opt) {
					case 'v' : verbose = 1;
							   break;
					default : break;
				}
		}
		int N = atoi(argv[1]);
		err_t noerr = OK;

		individu_t ** individus = NULL;
		fraction_t ** fractions = NULL;
		string_t ** strings = NULL;

		liste_t * liste = NULL ;
		int i = 0 ;

		individus = malloc(  sizeof(individu_t *) * N);
		fractions = malloc( sizeof(fraction_t *) * N);
		strings = malloc( sizeof(string_t *) * N );

		printf("Debut du programme des test sur les listes de %d objets homogenes\n", N);
		if (verbose == 1)
			printf("\nTest creation d'une liste de %d individus \n", N);
		char prenom[128] ;
		char nom[128] ;
		liste = liste_creer(N) ;
  		for( i=0 ; i<N ; i++ )
    	{
      		sprintf( nom , "nom_%d" , N-i ) ;
      		sprintf( prenom , "prenom_%d" , N-i ) ;
      		individus[i] = individu_creer( prenom , nom );
      		liste_elem_ecrire( liste , individus[i] , i ) ;
    	}
		if (verbose ==1)
  			printf( "Test affichage liste d'individus AVANT tri \n" ) ;
  		liste_afficher( liste , ' ' );
  		printf( "\n");
		if (verbose == 1)
  			printf( "Test Tri de la liste des individus\n" );
  		liste_trier( liste  ) ;
		if (verbose == 1)
  			printf( "Test affichage liste d'individus APRES tri\n" ) ;
  		liste_afficher( liste , ' ' );
  		printf( "\n");
		if (verbose == 1)
  			printf( "Test destruction liste d'individus\n" ) ;
  		if( ( noerr = liste_detruire( &liste ) ) )
    	{
      		printf("Sortie avec code erreur = %d\n" , noerr ) ;
      		return(noerr);
    	}
		if (verbose == 1)
  			printf( "\nTest creation d'une liste de %d fractions \n" , N ) ;
  		liste = liste_creer(N);
  		for( i=0 ; i<N ; i++ )
    	{
      		fractions[i] = fraction_creer( N-i , N-i+1 );
      		liste_elem_ecrire( liste , fractions[i] , i ) ;
    	}
		if (verbose == 1)
  			printf( "Test affichage liste de fractions AVANT tri\n" ) ;
  		liste_afficher( liste , ' ' );
  		printf( "\n");
		if (verbose == 1)
  			printf( "Test Tri de la liste des fractions\n" );
  		liste_trier( liste ) ;
		if (verbose ==1)
  			printf( "Test affichage liste des fractions APRES tri\n" ) ;
  		liste_afficher( liste ,  ' ' );
  		printf( "\n");
		if (verbose == 1)
  			printf( "Test destruction liste de fractions\n" ) ;
  		if( ( noerr = liste_detruire( &liste ) ) )
    	{
			printf("Sortie avec code erreur = %d\n" , noerr ) ;
      		return(noerr);
    	}
		if (verbose == 1)
  			printf( "\nTest creation d'une liste de %d strings \n" , N ) ;
  		char string[128] ;
  		liste = liste_creer(N);
  		for( i=0 ; i<N ; i++ )
    	{
      		sprintf( string , "string_%d" , N-i ) ;
      		strings[i] = string_creer( string ) ;
      		liste_elem_ecrire( liste , strings[i] , i ) ;
    	}
		if (verbose ==1)
  			printf( "Test affichage liste de strings AVANT tri\n" ) ;
  		liste_afficher( liste ,  ' ' ) ;
  		printf( "\n");
		if (verbose == 1)
  			printf( "Test Tri de la liste des strings\n" );
  		liste_trier( liste  ) ;
		if (verbose == 1)
  			printf( "Test affichage liste des strings APRES tri\n" ) ;
  		liste_afficher( liste ,  ' ' ) ;
  		printf( "\n");
		if (verbose == 1)
  			printf( "Test destruction liste de strings\n" ) ;
  		if( ( noerr = liste_detruire( &liste  ) ) ) {
      		printf("Sortie avec code erreur = %d\n" , noerr ) ;
      		return(noerr) ;
    	}

  		free( individus ) ;
  		free( fractions ) ;
  		free( strings ) ;
		if (verbose == 1)
  			printf("\nFin du programme des test sur la liste d'objets homogenes\n");
		printf( "Nombre de liste_t  = %lu\n" , liste_cpt ) ;
	}
	return 0;
}
