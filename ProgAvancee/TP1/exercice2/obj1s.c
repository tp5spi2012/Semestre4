#include <stdio.h>
#include <stdlib.h>

#include <obj1s.h>

/*
 * VARIABLES GLOBALES 
 */


/*
 * FONCTIONS
 */

/*
 * Methodes d'acces 
 */

/* Acces au nombre d'elements de la liste */

extern 
int obj1s_nb_lire( obj1s_t * const liste_obj1s )
{
  if( ! obj1s_existe( liste_obj1s ) )
    return(-1) ;

  return(liste_obj1s->nb );
} 

/* Acces a un element de la liste */

extern 
obj1_t  * obj1s_obj1_lire( obj1s_t * const liste_obj1s  , const int ind_obj1 )
{
  if( (ind_obj1 < 0) || (ind_obj1 > obj1s_nb_lire(liste_obj1s) ) )
    {
      fprintf( stderr , "obj1s_obj1_lire: mauvais indice de obj1 [%d] (devrait etre dans [%d..%d]\n",
	       ind_obj1 , 0 , obj1s_nb_lire(liste_obj1s) );
      return((obj1_t *)NULL);
    }

  return( liste_obj1s->liste[ind_obj1] ) ;
}



/*
 * Methodes d'affectation 
 */

/* Affectation d'un element */
extern 
err_t obj1s_obj1_ecrire( obj1s_t * liste_obj1s , 
		       obj1_t * const obj1 ,
		       const int ind_obj1 ) 
{
  err_t cr = OK ;

  if( (ind_obj1 < 0) || (ind_obj1 > obj1s_nb_lire(liste_obj1s) ) )
    {
      fprintf( stderr , "obj1s_obj1_ecrire: mauvais indice de obj1 [%d] (devrait etre dans [%d..%d]\n",
	       ind_obj1 , 0 , obj1s_nb_lire(liste_obj1s) );
      return(ERR_OBJ1_IND);
    }

  if( ( cr = obj1_copier( &(liste_obj1s->liste[ind_obj1]) , obj1 ) ) )
    return(cr) ; 

  return(OK) ;
}


/*
 * Creation d'une liste de obj1s 
 */
extern
obj1s_t * obj1s_creer( const int nb_obj1s )
{
  obj1s_t * liste_obj1s ;
  int i = 0 ;

  if(( liste_obj1s= malloc(sizeof(obj1s_t))) == NULL )
    {
      fprintf( stderr , "obj1s_creer: debordement memoire lors de la creation d'une liste de obj1s\n");
      return((obj1s_t *)NULL);
    }

  liste_obj1s->nb = 0;
  liste_obj1s->liste = (obj1_t **)NULL ;
  if( nb_obj1s > 0 ) 
    {
      if( (liste_obj1s->liste = malloc( sizeof(obj1_t *) * nb_obj1s )) == NULL )
	{
	  fprintf( stderr , "obj1s_creer: debordement memoire lors de la creation d'une liste de [%d] obj1s\n",
		   nb_obj1s ) ;
	  return((obj1s_t*)NULL);
	}

      for( i=0 ; i<nb_obj1s ; i++ ) 
	liste_obj1s->liste[i] = (obj1_t *)NULL ;

      liste_obj1s->nb = nb_obj1s ;
    }

  return(liste_obj1s);
}

/*
 * Destruction d'une liste de obj1s 
 */

extern
err_t obj1s_detruire( obj1s_t ** liste)
{

  return(OK) ;
}


/*
 * Affichage d'une liste de obj1s 
 */

extern 
void obj1s_afficher( obj1s_t * const obj1s )
{
  int i ;
  int nb_obj1s ;

  if( ! obj1s_existe(obj1s) )
    {
      printf("(liste d'objets inexistante)\n" );
      return ;
    }
  
  if( obj1s_vide(obj1s) )
    {
      printf("(liste d'objets vide)\n" );
      return ;
    }
  
  nb_obj1s = obj1s_nb_lire(obj1s) ;
  printf( "Nombre d'objets: %d\n" , nb_obj1s );  
  printf( "{ " ) ;
  for( i=0 ; i<nb_obj1s ; i++ ) 
    {
      if( (i!=0) && (i%10==0) ) printf("\n"); 
      if( i!=0 ) printf(" , ");      
      obj1_afficher( obj1s_obj1_lire( obj1s , i ) ) ; 

    }
   printf( " }\n" ) ;

}

/*
 * Copie d'une liste 
 * La liste source est copiee dans la liste cible
 * la liste cible est creee par la fonction 
 */

extern 
err_t obj1s_copier( obj1s_t ** s_cible , obj1s_t * const s_source ) 
{
  err_t cr = OK  ; 
  int nb_obj1s  ; 
  int i ;

  if( obj1s_existe( (*s_cible) ) )
    {
      if( (cr= obj1s_detruire( s_cible ) ) )
	return(cr) ;
    }

  if( ! obj1s_existe( s_source ) )
    return(OK) ;

  nb_obj1s = obj1s_nb_lire(s_source) ; 
  if( ( (*s_cible) = obj1s_creer(nb_obj1s) ) == NULL ) 
    return(ERR_DEB_MEMOIRE) ; 

  for( i=0 ; i<nb_obj1s ; i++ ) 
    {
      if( (cr = obj1_copier( &((*s_cible)->liste[i]) , 
			     obj1s_obj1_lire( s_source , i ) ) ) )
	return(cr) ;
    }    
       
  return(OK) ; 
}

/*
 * Tests
 */

extern 
booleen_t obj1s_existe( obj1s_t * const liste_obj1s )
{
  if( liste_obj1s == NULL )
    {
      return(FAUX) ; 
    }
  else
    {
      return(VRAI) ; 
    }
}

extern 
booleen_t obj1s_vide( obj1s_t * const liste_obj1s )
{
  if( liste_obj1s->nb == 0 )
    {
      return(VRAI) ; 
    }
  else
    {
      return(FAUX) ; 
    }
}
