#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <liste.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int liste_cpt = 0;

/*
 * Methodes d'acces
 *

/* Nombre d'elements */

extern int liste_nb_lire( liste_t * const liste )
{
  return(liste->nb );
}

/* -- Acces individuel a un element */

extern objet_t * liste_elem_lire( liste_t * const liste  , const int ind )
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

extern booleen_t liste_existe( liste_t * const liste )
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

extern booleen_t liste_vide( liste_t * const liste )
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
extern err_t liste_elem_ecrire( liste_t * liste , 
			 objet_t * const elem ,
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

extern liste_t * liste_creer (const int nb) {
	liste_t * liste;

	if ((liste = malloc(sizeof(liste_t))) == NULL) {
    	fprintf( stderr , "liste_creer: debordement memoire lors de la creation d'une liste\n");
		return((liste_t *)NULL);
    }

	liste->nb = nb ;
	liste->liste = (objet_t**)NULL ;
	if (nb > 0) {
		if ((liste -> liste = malloc(sizeof(objet_t *) * nb)) == NULL ) {
			fprintf( stderr , "liste_creer: debordement memoire lors de la creation d'une liste\n");
			free( liste );
			return (liste_t *)NULL;
		}
	}

	liste_cpt++ ;

	return liste;
}

/*
 * Destruction d'une liste
 */

extern err_t liste_detruire( liste_t ** liste ) {
	int i;
	for (i = 0; i < (*liste) -> nb; i++) {
		liste_t * tmp = malloc(sizeof(liste_t));
		tmp = *liste;
		(*liste) -> objet -> detruire((*liste) -> objet);
		free((*liste) -> objet);
		(*liste) = (*liste) -> suiv;
		(*tmp) -> suiv = NULL;
		(*tmp) -> prec = NULL;
		free(tmp);
	}
	free((*liste));
	return OK;
}


/*
 * Affichage d'une liste sur la sortie standard
 * avec un caractere de separation entre 
 * l'affichage de 2 elements 
 */

extern void liste_afficher (liste_t * const liste, const char separateur) {
	int i;
	for (i = 0; i < (*liste) -> nb; i++) {
		(*liste) -> objet -> afficher(*objet);
		printf("%c", separateur);
	}
}
