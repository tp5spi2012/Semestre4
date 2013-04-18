#include <stdlib.h>
#include <string.h>
#include <fraction.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int fraction_cpt = 0 ; 

/* 
 * FONCTIONS
 */

extern 
booleen_t fraction_existe( fraction_t * const fraction )
{
  if( fraction == NULL ) 
    return(FAUX) ;
  else
    return(VRAI) ; 
}

extern
err_t fraction_detruire( fraction_t ** fraction ) 
{

  /* Liberation attributs */
  /* Liberation memoire de l'objet */
  free( (*fraction) ) ;
  /* Pour eviter les pointeurs fous */
  (*fraction) = NULL ; 

  fraction_cpt-- ; 

  return(OK) ; 
}

extern
void fraction_afficher( fraction_t * const fraction ) 
{

  printf( "{" ) ; 
  if(  fraction_existe(fraction) ) 
    {
      printf( "%d/%d" , fraction->numerateur , fraction->denominateur ) ;
    }
  printf( "}" ) ; 
}

extern 
fraction_t * fraction_creer( const int numerateur , const int denominateur ) 
{
  fraction_t * fraction = NULL ; 

  /* Creation place memoire objet fraction */
  if( ( fraction = malloc(sizeof(fraction_t)) ) == NULL )
    {
      fprintf( stderr , "fraction_creer: debordement memoire lors de la creation d'un objet de type fraction_t (%lu demandes)\n", 
	       (unsigned long int)sizeof(fraction_t) ) ;
      return((fraction_t *)NULL);
    }

  /* Affectation attributs specifiques */
  fraction->numerateur = numerateur; 
  fraction->denominateur = denominateur ;
  
  fraction_cpt++ ; 

  return( fraction ) ;
}

extern
int fraction_comparer( const fraction_t * const f1 , const fraction_t * const f2 ) 
{
  float r1 = (float) f1->numerateur / f1->denominateur  ; 
  float r2 = (float) f2->numerateur / f2->denominateur  ; 
  if( r1 == r2 ) return(0) ; 
  if( r1 > r2 )  return(1) ; 
  return(-1) ;   
}


