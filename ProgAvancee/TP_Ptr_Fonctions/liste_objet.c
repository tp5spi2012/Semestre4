#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <liste_objet.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int liste_objet_cpt = 0 ; 

/*
 * Methodes d'acces 
 */

/* Nombre d'elements */

static 
int liste_objet_nb_lire( liste_objet_t * const liste )
{
  return(liste->nb );
} 

/* -- Acces individuel a un element */

static 
objet_t * liste_objet_elem_lire( liste_objet_t * const liste  , const int ind )
{
  if( (ind < 0) || (ind > liste->nb_lire(liste)-1 ) )
    {
      fprintf( stderr , "liste_elem_lire: mauvais indice d'element [%d] (devrait etre dans [%d..%d])\n",
	       ind , 0 , liste->nb_lire(liste)-1 );
      return(NULL);
    }

  return( liste->liste[ind] ) ;
}

/*
 * Tests 
 */

extern 
booleen_t liste_objet_existe( liste_objet_t * const liste )
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

static 
booleen_t liste_objet_vide( liste_objet_t * const liste )
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
static 
err_t liste_objet_elem_ecrire( liste_objet_t * liste , 
			 objet_t * const elem ,
			 const int ind ) 
{

#ifdef _DEBUG_
  if( (ind < 0) || (ind > liste->nb_lire(liste)-1 ) )
    {
      fprintf( stderr , "liste_elem_ecrire: mauvais indice d'element [%d] (devrait etre dans [%d..%d]\n",
	       ind , 0 , liste->nb_lire(liste)-1 );
      return(ERR_LISTE_IND_ELEM);
    }
#endif
  liste->liste[ind] = elem ;

  return(OK) ;
}


/*
 * Destruction d'une liste 
 */

static
err_t liste_objet_detruire( liste_objet_t ** liste )
{
	if(liste_objet_existe(*liste)) {
		int i = 0;
		objet_t *o;
	
		if(!(*liste)->vide(*liste))
			for(; i < (*liste)->nb_lire(*liste); i++)
				if((o = liste_objet_elem_lire(*liste, i)) != NULL) 
					o->detruire(&o);
					
		(*liste)->detruire = NULL;
		(*liste)->afficher = NULL;
		(*liste)->nb_lire = NULL;
		(*liste)->elem_lire = NULL;
		(*liste)->vide = NULL;
		(*liste)->elem_ecrire = NULL;
		
		free((*liste)->liste);
		free(*liste);
		
		liste_objet_cpt--;
	}

  return(OK) ;
}


/*
 * Affichage d'une liste sur la sortie standard
 * avec un caractere de separation entre 
 * l'affichage de 2 elements 
 */

static 
void liste_objet_afficher( liste_objet_t * const liste ,
		     const char separateur )
{
  if(liste_objet_existe(liste) && !liste->vide(liste)) {
  	int i = 0;
  	objet_t *o = NULL;
  	
  	for(; i < liste->nb_lire(liste); i++) {
  		if((o = liste_objet_elem_lire(liste, i)) != NULL) {
				o->afficher(o);
				printf("%c", separateur);
  		}
  	}
  }
}

/*
 * Creation d'une liste 
 */
extern
liste_objet_t * liste_objet_creer( const int nb )
{
	int i = 0;
  liste_objet_t * liste ;
  
  if(( liste= malloc(sizeof(liste_objet_t))) == NULL )
    {
      fprintf( stderr , "liste_creer: debordement memoire lors de la creation d'une liste\n");
      return((liste_objet_t *)NULL);
    }

  liste->nb = nb ;
  liste->liste = (objet_t**)NULL ;
  if( nb > 0 ) 
    {
      if( ( liste->liste = malloc( sizeof(objet_t *) * nb ) ) == NULL ) 
	{
	  fprintf( stderr , "liste_creer: debordement memoire lors de la creation d'une liste\n");
	  free( liste ) ;
	  return((liste_objet_t *)NULL);
	}
    }
    
  for(; i < nb ; i++)
  	*(liste->liste + i) = NULL;

	liste->detruire = liste_objet_detruire;
	liste->afficher = liste_objet_afficher;
	liste->nb_lire = liste_objet_nb_lire;
	liste->elem_lire = liste_objet_elem_lire;
	liste->vide = liste_objet_vide;
	liste->elem_ecrire = liste_objet_elem_ecrire;

  liste_objet_cpt++ ; 

  return(liste);
}
