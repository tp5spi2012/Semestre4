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

static 
err_t fraction_detruire( fraction_t ** fraction ) 
{ 
  (*fraction)->detruire = NULL;
  (*fraction)->afficher = NULL;
  
  free(*fraction);
  
  fraction_cpt--;

  return(OK) ; 
}

static
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
 
 	fraction = (fraction_t *)malloc(sizeof(fraction_t));
	
	fraction->numerateur = numerateur;
	fraction->denominateur = denominateur;
	fraction->detruire = (err_t (*)(objet_t**)) fraction_detruire;
	fraction->afficher = (void (*)(objet_t *)) fraction_afficher;
	
	fraction_cpt++;

  return( fraction ) ;
}
