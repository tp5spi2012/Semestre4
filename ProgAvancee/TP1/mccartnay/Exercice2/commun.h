#ifndef _COMMUN_H_
#define _COMMUN_H_

#include <stdio.h>

/* Definition du type booleen */
typedef enum booleen_s { FAUX , VRAI } booleen_t ;

/* Definition du type erreur */
typedef int err_t ; 

/* Constantes */

#define TAILLE 32

/* Erreurs */
#define OK 0

#define ERR_DEB_MEMOIRE -100 
#define ERR_OBJ1_IND -200
#define ERR_OBJ2_IND -300


#endif

