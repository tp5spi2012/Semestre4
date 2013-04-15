#ifndef _LISTE_SDD_H_
#define _LISTE_SDD_H_

#include <commun.h>
#include <objet.h>


#define LISTE_NULL NULL
#define LISTE_ID_NULL -1


typedef struct liste_s
{
  int nb ;		/* Nombre d'objets dans la liste  */
  objet_t ** liste ;	/* liste  des objets */
} liste_t ;

#endif
