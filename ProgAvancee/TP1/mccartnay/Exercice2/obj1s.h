#ifndef _OBJ1S_H_
#define _OBJ1S_H_

#include <obj1.h>


/*
 * CONSTANTES 
 */


/*
 * TYPES
 */



/* Liste de obj1  */
typedef struct obj1s_s
{
  int nb ;		/*!< Nombre de obj1 */
  obj1_t ** liste ;	/*!< Liste des obj1 */
} obj1s_t ;

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

/*! Acces au nombre des obj1s */
extern int obj1s_nb_lire( obj1s_t * const liste_obj1s );

/*! Acces individuel a un obj1 */
extern obj1_t * obj1s_obj1_lire( obj1s_t * const liste_obj1s  , const int ind_obj1 );

/*!
 * @}
 * \name Tests 
 * @{
 */

/*! Test si la liste de obj1s existe */
extern booleen_t obj1s_existe( obj1s_t * const liste_obj1s ) ; 

/*! Test si la liste de obj1s est vide (pas de obj1s dedans) */
extern booleen_t obj1s_vide( obj1s_t * const liste_obj1s ) ; 

/*!
 * @}
 * \name Methodes d'affectations 
 * @{
 */

/*! Affectation d'un obj1 */
extern err_t obj1s_obj1_ecrire( obj1s_t * liste_obj1s , 
				obj1_t  * const obj1 ,
				const int ind_obj1 ) ;

/*! 
 * @}
 * \name Primitives 
 * @{
 */

/*!
 * Creation d'une liste de obj1s
 */
extern obj1s_t * obj1s_creer( const int nb_obj1s );

/*!
 * Destruction d'une liste de obj1ings
 */
extern err_t obj1s_detruire( obj1s_t ** liste);

/*!
 * Affichage d'une liste de obj1ings
 */
extern void obj1s_afficher( obj1s_t * const obj1s );

/*!
 * \fn err_t obj1s_copier( obj1s_t ** l_cible , obj1s_t * const l_source ) 
 * \brief Copie d'une liste d'obj1
 * La liste source est copiee dans la liste cible.<br>
 * La liste cible est creee par la fonction 
 * \param[out] s_cible : liste cible 
 * \param[in] s_source : liste source 
 */
extern err_t obj1s_copier( obj1s_t ** l_cible , obj1s_t * const l_source ) ;

/*! @} */

#endif
