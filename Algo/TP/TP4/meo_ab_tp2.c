// HUBA Thomas - Structure de l'arbre n-aire (type : division administrative)

#include "meo_ab_tp2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definition d'un noeud de l'arbre
typedef struct noeud {
	t_divadmin * division;
	struct noeud * pere; 
	struct noeud * frere; 
	struct noeud * fils;
		} t_noeud;

// Creation des elements de l'arbre de type t_noeud
t_noeud * racine;
t_noeud * nc;

/*
 * INIT ARBRE
 */
// Initialise l'arbre
void init_arbre(void){	
	racine=NULL;
	nc=NULL;
}

/*
 * ARBRE VIDE
 */
// Retourne vrai si l'arbre est vide
int arbre_vide(void){
	return (racine==NULL);
}

/*
 * HORS ARBRE
 */
// Retourne vrai si l'element courant est hors arbre
int hors_arbre(void){
	return (nc==NULL);
}

/*
 * FRERE
 */
// Retourne vrai si l'element courant possede un frere
int frere(void){	
	if(!hors_arbre())	
		return(nc->frere!=NULL);
	return 0;
}

/*
 * FEUILLE
 */
// Retourne vrai si l'element courant est une feuille
int feuille(void){
	if(!hors_arbre())	
		return(nc->fils==NULL);
	return 0;
}

/*
 * POSIT RAC
 */
// Positionne l'element courant sur la racine
void posit_rac(void){
	if(!arbre_vide()) 
		nc=racine;
}

/*
 * POSIT PERE
 */
// Positionne l'element courant sur le pere de celui-ci
void posit_pere(void){
	if(!hors_arbre()) 
		nc=nc->pere;
}

/*
 * POSIT FILS
 */
// Positionne l'element courant sur le fils de celui-ci
void posit_fils(void){
	if(!hors_arbre()) 
		nc=nc->fils;
}

/*
 * VAL NOEUD
 */
// Recupere la valeur du noeud courant
void val_noeud(t_divadmin * i){
	if(!hors_arbre()) 
		*i=nc->division;
}

/*
 * MODIF NOEUD
 */
// Modifie la valeur du noeud courant, celle-ci etant recu en parametre
void modif_noeud(t_divadmin * i){
	if(!hors_arbre()) 
		nc->division=*i;
}

/*
 * OTER FEUILLE
 */
// Supprime la l'element courant, si c'est une feuille
void oter_feuille(void){
	struct noeud * ancien;
	if(!hors_arbre())
		if(feuille()){
			if(nc==racine){ 
				free(nc);
				racine=NULL;
			}
			else{
				ancien=nc;
				if(nc==(nc->pere)->fils){
					(nc->frere)->pere=nc->pere;
					free(ancien);
				}
				if(frere()){
					do{
						posit_frere();
						ancien=nc;
						
					}while(ancien!=)
				}
				else
					ancien=NULL;
				posit_pere();
				free(ancien);
			}
		}
}


void ajout_filsg(int i){	
	t_noeud * nouveau;
	if(arbre_vide()){
		racine=(t_noeud *)malloc(sizeof(t_noeud));
		racine->val=i;
		racine->pere=NULL;
		racine->gauche=NULL;
		racine->droit=NULL;
		nc=racine;
	}
	else if(!hors_arbre()&&!filsg()){
		nouveau=(t_noeud *)malloc(sizeof(t_noeud));
		nouveau->val=i;
		nouveau->pere=nc;
		nouveau->gauche=NULL;
		nouveau->droit=NULL;
		nc->gauche=nouveau;
		nc=nouveau;
	}
}

void ajout_filsd(int i){
	t_noeud * nouveau;
	if(arbre_vide())
		ajout_filsg(i);
	else if(!hors_arbre()&&!filsd())
	{	nouveau=(t_noeud *)malloc(sizeof(t_noeud));
		nouveau->val=i;
		nouveau->pere=nc;
		nouveau->gauche=NULL;
		nouveau->droit=NULL;
		nc->droit=nouveau;
		nc=nouveau;
	}
}
