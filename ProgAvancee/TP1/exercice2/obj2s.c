#include <stdio.h>
#include <stdlib.h>

#include <obj2s.h>

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
int obj2s_nb_lire( obj2s_t * const liste_obj2s )
{
  if( ! obj2s_existe( liste_obj2s ) )
    return(-1) ;

  return(liste_obj2s->nb );
} 

/* Acces a un element de la liste */

extern 
obj2_t  * obj2s_obj2_lire( obj2s_t * const liste_obj2s  , const int ind_obj2 )
{
  if( (ind_obj2 < 0) || (ind_obj2 > obj2s_nb_lire(liste_obj2s) ) )
    {
      fprintf( stderr , "obj2s_obj2_lire: mauvais indice de obj2 [%d] (devrait etre dans [%d..%d]\n",
	       ind_obj2 , 0 , obj2s_nb_lire(liste_obj2s) );
      return((obj2_t *)NULL);
    }

  return( liste_obj2s->liste[ind_obj2] ) ;
}



/*
 * Methodes d'affectation 
 */


/* Affectation d'un element */
extern 
err_t obj2s_obj2_ecrire( obj2s_t * liste_obj2s , 
			 obj2_t * const obj2 ,
			 const int ind_obj2 ) 
{
  err_t cr = OK ;

  if( (ind_obj2 < 0) || (ind_obj2 > obj2s_nb_lire(liste_obj2s) ) )
    {
      fprintf( stderr , "obj2s_obj2_ecrire: mauvais indice de obj2 [%d] (devrait etre dans [%d..%d]\n",
	       ind_obj2 , 0 , obj2s_nb_lire(liste_obj2s) );
      return(ERR_OBJ2_IND);
    }

  if( ( cr = obj2_copier( &(liste_obj2s->liste[ind_obj2]) , obj2 ) ) )
    return(cr) ; 

  return(OK) ;
}


/*
 * Creation d'une liste de obj2s 
 */
extern
obj2s_t * obj2s_creer( const int nb_obj2s )
{
  obj2s_t * liste_obj2s ;
  int i = 0 ;

  if(( liste_obj2s= malloc(sizeof(obj2s_t))) == NULL )
    {
      fprintf( stderr , "obj2s_creer: debordement memoire lors de la creation d'une liste de obj2s\n");
      return((obj2s_t *)NULL);
    }

  liste_obj2s->nb = 0;
  liste_obj2s->liste = (obj2_t **)NULL ;
  if( nb_obj2s > 0 ) 
    {
      if( (liste_obj2s->liste = malloc( sizeof(obj2_t *) * nb_obj2s )) == NULL )
	{
	  fprintf( stderr , "obj2s_creer: debordement memoire lors de la creation d'une liste de [%d] obj2s\n",
		   nb_obj2s ) ;
	  return((obj2s_t*)NULL);
	}

      for( i=0 ; i<nb_obj2s ; i++ ) 
	liste_obj2s->liste[i] = (obj2_t *)NULL ;

      liste_obj2s->nb = nb_obj2s ;
    }

  return(liste_obj2s);
}

/*
 * Destruction d'une liste de obj2s 
 */

extern
err_t obj2s_detruire( obj2s_t ** liste)
{

  return(OK) ;
}


/*
 * Affichage d'une liste de obj2s 
 */

extern 
void obj2s_afficher( obj2s_t * const obj2s )
{
  int i ;
  int nb_obj2s ;

  if( ! obj2s_existe(obj2s) )
    {
      printf("(liste d'objets inexistante)\n" );
      return ;
    }
  
  if( obj2s_vide(obj2s) )
    {
      printf("(liste d'objets vide)\n" );
      return ;
    }
  
  nb_obj2s = obj2s_nb_lire(obj2s) ;
  printf( "Nombre d'objets: %d\n" , nb_obj2s );  
  printf( "{ " ) ;
  for( i=0 ; i<nb_obj2s ; i++ ) 
    {
      if( (i!=0) && (i%10==0) ) printf("\n"); 
      if( i!=0 ) printf(" , ");      
      obj2_afficher( obj2s_obj2_lire( obj2s , i ) ) ; 

    }
   printf( " }\n" ) ;

}

/*
 * Copie d'une liste 
 * La liste source est copiee dans la liste cible
 * la liste cible est creee par la fonction 
 */

extern 
err_t obj2s_copier( obj2s_t ** s_cible , obj2s_t * const s_source ) 
{
  err_t cr = OK  ; 
  int nb_obj2s  ; 
  int i ;

  if( obj2s_existe( (*s_cible) ) )
    {
      if( (cr= obj2s_detruire( s_cible ) ) )
	return(cr) ;
    }

  if( ! obj2s_existe( s_source ) )
    return(OK) ;

  nb_obj2s = obj2s_nb_lire(s_source) ; 
  if( ( (*s_cible) = obj2s_creer(nb_obj2s) ) == NULL ) 
    return(ERR_DEB_MEMOIRE) ; 

  for( i=0 ; i<nb_obj2s ; i++ ) 
    {
      if( (cr = obj2_copier( &((*s_cible)->liste[i]) , 
			     obj2s_obj2_lire( s_source , i ) ) ) )
	return(cr) ;
    }    
       
  return(OK) ; 
}

/*
 * Tests
 */

extern 
booleen_t obj2s_existe( obj2s_t * const liste_obj2s )
{
  if( liste_obj2s == NULL )
    {
      return(FAUX) ; 
    }
  else
    {
      return(VRAI) ; 
    }
}

extern 
booleen_t obj2s_vide( obj2s_t * const liste_obj2s )
{
  if( liste_obj2s->nb == 0 )
    {
      return(VRAI) ; 
    }
  else
    {
      return(FAUX) ; 
    }
}
