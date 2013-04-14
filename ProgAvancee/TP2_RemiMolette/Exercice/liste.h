#ifndef _LISTE_H_
#define _LISTE_H_

#include <liste_sdd.h>

extern unsigned long int liste_cpt  ;

/*
 * FONCTIONS
 */

/*!
 * \name Methodes d'acces 
 * @{
 */

/*! Acces au nombre d'objets */
extern int liste_nb_lire( liste_t * const liste );

/*! Acces a un objets de la liste */
extern objet_t * liste_elem_lire( liste_t * const liste , const int ind );

/*!
 * @}
 * \name Tests 
 * @{
 */

/*! Teste si la liste existe */
extern booleen_t liste_existe( liste_t * const liste) ; 

/*! Teste si la liste est vide (aucun &eacute;l&eacute;ment dedans) */
extern booleen_t liste_vide( liste_t * const liste) ; 

/*!
 * @}
 * \name Methodes d'affectations 
 * @{
 */

/*! Affectation d'un objet */
extern err_t liste_elem_ecrire( liste_t * liste, 
				objet_t * const elem ,
				const int ind ) ;

/*!
 * @}
 * \name Primitives
 * @{
 */

/*!
 * Creation d'une liste 
 */
extern liste_t * liste_creer( const int nb);

/*!
 * Destruction d'une liste 
 */

extern err_t liste_detruire( liste_t ** liste );


/*! 
 * \name Affichage
 * @{
 */

/*!
 * Affichage d'une liste sur la sortie standard
 */

extern void liste_afficher( liste_t * const liste , 
			    const char separateur );

/*!
 * @}
 */

/*! @} */
#endif
