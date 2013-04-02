#include <stdlib.h>
#include <string.h>
#include <obj2.h>


/*
 * VARIABLE LOCALE
 */

/* 
 * FONCTIONS
 */

extern 
obj2_t * obj2_creer( const int nb_obj1 ) 
{
  obj2_t * obj2 = NULL ; 
  static unsigned long int cpt = 0 ; 
  int i = 0 ; 
  
  if( ( obj2 = malloc(sizeof(obj2_t)) ) == NULL )
    {
      fprintf( stderr , "obj2_creer: debordement memoire lors de la creation d'un objet de type obj2_t (%lu demandes)\n", 
	       (unsigned long int)sizeof(obj2_t) ) ;
      return((obj2_t *)NULL);
    }
  
  if( ( obj2->liste_objets = obj1s_creer(nb_obj1) ) == NULL )
    {
      fprintf( stderr , "obj2_creer: debordement memoire lors de la creation de la liste des obj1 d'un obj2_t\n" ) ;
      return((obj2_t *)NULL);
    }

  if( ( obj2->attributs = malloc( sizeof(char)*TAILLE ) ) == NULL )
    {
      fprintf( stderr , "obj2_creer: debordement memoire lors de la creation des attributs d'un obj2_t (%lu demandes)\n", 
	       (unsigned long int)sizeof(char)*TAILLE ) ;
      return((obj2_t *)NULL);
    }

  /* Initialisation des attributs */
  
  for( i=0 ; i<nb_obj1 ; i++ ) 
    {
      if( ( obj2->liste_objets->liste[i] = obj1_creer() ) == NULL )
	{
	  fprintf( stderr , "obj2_creer: debordement memoire lors de l'initialisation de la liste des obj1 d'un obj2_t\n" ) ;
	  return((obj2_t *)NULL);
	}
    }

  cpt++ ;
  char w[TAILLE] ;
  sprintf( w , "[objet2] %lu" , cpt ); 
  strcpy( obj2->attributs , w ); 
  
  return( obj2 ) ;
}

extern 
err_t obj2_detruire( obj2_t ** obj2 ) 
{

  return(OK) ; 
}


extern 
booleen_t obj2_existe( obj2_t * const obj2 )
{
  if( obj2 == NULL ) 
    return(FAUX) ;
  else
    return(VRAI) ; 
}

extern
err_t obj2_copier( obj2_t ** obj2_cible , obj2_t * const obj2_source )
{
  err_t noerr = OK ; 

  if( ! obj2_existe( (*obj2_cible) ) )
    {
      if( ( (*obj2_cible) = obj2_creer( obj1s_nb_lire(obj2_source->liste_objets) ) ) == NULL )
	{
	  fprintf( stderr , "obj2_copier: debordement memoire lors de la creation d'un objet cible \n " ) ;
	  return(ERR_DEB_MEMOIRE);
	}
    }
 
  if( ( noerr = obj1s_detruire( &((*obj2_cible)->liste_objets)) ) )
    return(noerr) ; 

  if( ( noerr = obj1s_copier( &((*obj2_cible)->liste_objets) , obj2_source->liste_objets ) ) )
    return(noerr) ; 

  strcpy(  (*obj2_cible)->attributs , obj2_source->attributs ) ;

  return(OK) ; 
}


extern
void obj2_afficher( obj2_t * const obj2 ) 
{

  printf( "{\n" ) ; 
  if(  obj2_existe(obj2) ) 
    {
      printf("\t") ;
      printf( "%s" , obj2->attributs ) ;
      printf("\n\t") ;
      obj1s_afficher( obj2->liste_objets ) ;
    }
  printf( "}" ) ; 
}
