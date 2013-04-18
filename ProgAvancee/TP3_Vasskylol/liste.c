#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <liste.h>

#include <stdarg.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int liste_cpt = 0 ; 

/*
 * Methodes d'acces 
 */

/* Nombre d'elements */

extern 
int liste_nb_lire( liste_t * const liste )
{
  return(liste->nb );
} 

/* -- Acces individuel a un element */

extern 
void * liste_elem_lire( liste_t * const liste  , const int ind )
{
  if( (ind < 0) || (ind > liste_nb_lire(liste)-1 ) )
    {
      fprintf( stderr , "liste_elem_lire: mauvais indice d'element [%d] (devrait etre dans [%d..%d])\n",
	       ind , 0 , liste_nb_lire(liste)-1 );
      return(NULL);
    }

  return( liste->liste[ind] ) ;
}

/*
 * Tests 
 */

extern 
booleen_t liste_existe( liste_t * const liste )
{
  if( liste == NULL )
    {
      return(FAUX) ; 
    }
  else
    {
      return(VRAI) ; 
    }
}

extern 
booleen_t liste_vide( liste_t * const liste )
{
  if( liste->nb == 0 )
    {
      return(VRAI) ; 
    }
  else
    {
      return(FAUX) ; 
    }
}

/*
 * Methodes d'affectation 
 */


/* -- Acces individuel a un element */
extern 
err_t liste_elem_ecrire( liste_t * liste , 
			 void * const elem ,
			 const int ind ) 
{

#ifdef _DEBUG_
  if( (ind < 0) || (ind > liste_nb_lire(liste) ) )
    {
      fprintf( stderr , "liste_elem_ecrire: mauvais indice d'element [%d] (devrait etre dans [%d..%d]\n",
	       ind , 0 , liste_nb_lire(liste) );
      return(ERR_LISTE_IND_ELEM);
    }
#endif
  liste->liste[ind] = elem ;

  return(OK) ;
}


/*
 * Creation d'une liste 
 */
extern
liste_t * liste_creer( const int nb )
{
  liste_t * liste ;
  
  if(( liste= malloc(sizeof(liste_t))) == NULL )
    {
      fprintf( stderr , "liste_creer: debordement memoire lors de la creation d'une liste\n");
      return((liste_t *)NULL);
    }

  liste->nb = nb ;
  liste->liste = (void**)NULL ;
  if( nb > 0 ) 
    {
      if( ( liste->liste = malloc( sizeof(void *) * nb ) ) == NULL ) 
	{
	  fprintf( stderr , "liste_creer: debordement memoire lors de la creation d'une liste\n");
	  free( liste ) ;
	  return((liste_t *)NULL);
	}
    }

  liste_cpt++ ; 

  return(liste);
}

/*
 * Destruction d'une liste 
 *
 * L'appel à cette fonction doit se terminer par NULL.
 */

extern
err_t liste_detruire( liste_t ** liste , ... )
{
  printf("Destruction\n");
  if(liste != NULL && liste_existe(*liste) && !liste_vide(*liste)) {
    int i = 0;
    va_list ap;
    err_t (*p)(void **);

    va_start(ap, liste);
    if(va_arg(ap, err_t (*)(void **)) != NULL)
      p = va_arg(ap, err_t (*)(void **));

    for(; i < (*liste)->nb; i++)
      p(&((*liste)->liste[i]));
    free(*liste);

    va_end(ap);    
  }
  return(OK) ;
}


/*
 * Affichage d'une liste sur la sortie standard
 *
 * L'appel à cette fonction doit contenir le nombre d'arguments.
 *
 */

extern 
void liste_afficher( liste_t * const liste, int nb_arg, ...)
{
  if(liste_existe(liste) && !liste_vide(liste)) {
    va_list ap;
    int i = 0;
    void (*p)(void * const);
 
    va_start(ap, nb_arg);
    p = va_arg(ap, void * const);
    for(; i < liste->nb ; i++)
      p(liste->liste[i]);
    va_end(ap);
  }
  return ;
}

/*
* Tri d'une liste 
 * 
 * A FAIRE 
 *
 */

extern
err_t liste_trier( liste_t * liste , ... )
{
  /*
   * A FAIRE 
   */

  return(OK) ; 
}
