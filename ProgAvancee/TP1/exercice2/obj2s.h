#ifndef _OBJ2S_H_
#define _OBJ2S_H_

#include <obj2.h>


/*
 * CONSTANTES 
 */


/*
 * TYPES
 */



/* Liste de obj2  */
typedef struct obj2s_s
{
  int nb ;		/*!< Nombre de obj2 */
  obj2_t ** liste ;	/*!< Liste des obj2 */
} obj2s_t ;

/*
 * VARIABLE LOCALE
 */

/*
 * FONCTIONS
 */

/*!
 * \name Methodes d'acces 
 * @{
 */

/*! Acces au nombre des obj2s */
extern int obj2s_nb_lire( obj2s_t * const liste_obj2s );

/*! Acces individuel a un obj2 */
extern obj2_t * obj2s_obj2_lire( obj2s_t * const liste_obj2s  , const int ind_obj2 );

/*!
 * @}
 * \name Tests 
 * @{
 */

/*! Test si la liste de obj2s existe */
extern booleen_t obj2s_existe( obj2s_t * const liste_obj2s ) ; 

/*! Test si la liste de obj2s est vide (pas de obj2s dedans) */
extern booleen_t obj2s_vide( obj2s_t * const liste_obj2s ) ; 

/*!
 * @}
 * \name Methodes d'affectations 
 * @{
 */

/*! Affectation d'un obj2 */
extern err_t obj2s_obj2_ecrire( obj2s_t * liste_obj2s , 
				obj2_t  * const obj2 ,
				const int ind_obj2 ) ;

/*! 
 * @}
 * \name Primitives 
 * @{
 */

/*!
 * Creation d'une liste de obj2s
 */
extern obj2s_t * obj2s_creer( const int nb_obj2s );

/*!
 * Destruction d'une liste de obj2ings
 */
extern err_t obj2s_detruire( obj2s_t ** liste);

/*!
 * Affichage d'une liste de obj2ings
 */
extern void obj2s_afficher( obj2s_t * const obj2s );

/*!
 * \fn err_t obj2s_copier( obj2s_t ** l_cible , obj2s_t * const l_source ) 
 * \brief Copie d'une liste d'obj2
 * La liste source est copiee dans la liste cible.<br>
 * La liste cible est creee par la fonction 
 * \param[out] s_cible : liste cible 
 * \param[in] s_source : liste source 
 */
extern err_t obj2s_copier( obj2s_t ** l_cible , obj2s_t * const l_source ) ;

/*! @} */

#endif
