// HUBA Thomas - Primitive oriente arbre n-aire

/*
 * LIB
 */

#include <stdlib.h>
#include <sdtio.h>
#include <string.h>

/*
 * DATA
 */

// Definition de la valeur des noeuds
typedef struct {
	char name[30];
	int population;
	char capital[30];
	t_type type;
	} t_divadmin;

// Definition du type de d'element d'un noeud 
typedef enum {pays,region,departement,ville} t_type;

/*
 * TOOLS
 */

typedef enum {false,true} bool;

/*
 * END
 */

// Primitives

/*
 * COMPARAISON
 */
// Retourne vrai si les deux divisions sont égals
bool comparaison(){
	// TODO
	return true;
}

/*
 * SUPPRESSION
 */
// Supprime le noeud courant
void suppression(t_noeud * noeud){
	// TODO
}

/*
 * CREATION
 */
// Cree un noeud dans l'arbre
void creation(){
	// TODO
}

/*
 * MODIFICATION
 */
// Modifie la valeur du noeud courant
void modification(){
	// TODO
}

