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

static err_t fraction_detruire(fraction_t ** fraction) {
	(*fraction) -> afficher = NULL;
	(*fraction) -> detruire = NULL;
	free(fraction);
	(*fraction) = NULL;
	fraction_cpt--;
	return OK;
}

static err_t fraction_detruire_cb (objet_t ** fraction) {
	fraction_detruire((fraction_t **) fraction);
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

static void fraction_afficher_cb (objet_t * fraction) {
	fraction_afficher((fraction_t *) fraction);
}

extern fraction_t * fraction_creer (const int numerateur, const int denominateur) {
	fraction_t * fraction = NULL;
	fraction = malloc(sizeof(fraction_t));
	fraction -> numerateur = numerateur;
	fraction -> denominateur = denominateur;
	fraction -> afficher = fraction_afficher_cb;
	fraction -> detruire = fraction_detruire_cb;
	fraction_cpt++;
	return fraction;
}
