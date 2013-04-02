#include <stdlib.h>
#include <string.h>
#include <obj1.h>


/*
 * VARIABLE LOCALE
 */

/* 
 * FONCTIONS
 */

extern 
obj1_t * obj1_creer() 
{
  obj1_t * obj1 = NULL ; 
  static unsigned long int cpt = 0 ; 
  char w[TAILLE] ;
  
  if( ( obj1 = malloc(sizeof(obj1_t)) ) == NULL )
    {
      fprintf( stderr , "obj1_creer: debordement memoire lors de la creation d'un objet de type obj1_t (%lu demandes)\n", 
	       (unsigned long int)sizeof(obj1_t) ) ;
      return((obj1_t *)NULL);
    }
  
  if( ( obj1->attributs = malloc( sizeof(char)*TAILLE ) ) == NULL )
    {
      fprintf( stderr , "obj1_creer: debordement memoire lors de la creation des attributs d'un obj1_t (%lu demandes)\n", 
	       (unsigned long int)sizeof(char)*TAILLE ) ;
      return((obj1_t *)NULL);
    }
    
  cpt++ ;
  sprintf( w , "[objet1] %lu" , cpt ); 
  strcpy( obj1->attributs , w ); 
    
  return( obj1 ) ;
}

extern 
err_t obj1_detruire( obj1_t ** obj1 ) 
{

  return(OK) ; 
}


extern 
booleen_t obj1_existe( obj1_t * const obj1 )
{
  if( obj1 == NULL ) 
    return(FAUX) ;
  else
    return(VRAI) ; 
}

extern
err_t obj1_copier( obj1_t ** obj1_cible , obj1_t * const obj1_source )
{

  if( ! obj1_existe( (*obj1_cible) ) )
    {
      if( ( (*obj1_cible) = obj1_creer() ) == NULL )
	{
	  fprintf( stderr , "obj1_copier: debordement memoire lors de la creation d'un objet cible \n " ) ;
	  return(ERR_DEB_MEMOIRE);
	}
    }
 
  strcpy(  (*obj1_cible)->attributs , obj1_source->attributs ) ;

  return(OK) ; 
}


extern
void obj1_afficher( obj1_t * const obj1 ) 
{

  printf( "{" ) ; 
  if(  obj1_existe(obj1) ) 
    {
      printf( "%s" , obj1->attributs ) ;
    }
  printf( "}" ) ; 
}
