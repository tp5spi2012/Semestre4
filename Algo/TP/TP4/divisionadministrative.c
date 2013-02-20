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


    /*Proposition de Colas
    t_divadmin creation(void) {     Cette fonction renvoie un division administrative (DA), sans prendre de param

    t_divadmin * val;
    val=(t_divadmin *)malloc(sizeof(t_divadmin));
    int choix;      //Cette variable sert pour le type enum

    //---------Entrée du nom de la DA-----------
    printf("Entrez le nom de la division administrative : ");
    scanf("%s", val->nom);

    //Entrée du nombre d'haibitant
    printf("Entrez le nombre d'habitant : ");
    scanf("%i", val->population);

    //Choix du type de DA, combiné avec l'entrée du nom de la ville (cette partie fait les deux traitements d'un coup)

    do {
        printf("Choisissez le type de division administrative : \n Pays -->1\n Région-->2\n Département-->3\n Ville-->4\n votre choix : ");
        scanf("%i", &choix);

    } while (choix <1 && choix >4);     //boucle pour éviter l'entrée d'autre chose que les valeurs attendues

    switch (choix) {

        case 1 :
            val->local = pays;
            printf("Entrez le nom de la capitale : ");
            scanf("%s", val->capital);
            break;

        case 2 :
            val->local = region;
            printf("Entrez le nom du chef-lieu régionnal : ");
            scanf("%s", val->capital);
            break;

        case 3 :
            val->local = departement;
            printf("Entrez le nom de la préfecture : ");
            scanf("%s", val->capital);
            break;

        case 4 :
            val->local = ville;
            printf("Entrez l'ancien nom de la ville : ");
            scanf("%s", val->capital);
            break;
    }
    return val;     //on retourne la division administrative.
}*/
	// TODO
}

/*
 * MODIFICATION
 */
// Modifie la valeur du noeud courant
void modification(){
	// TODO
}

