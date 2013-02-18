/* Mise en oeuvre par pointeurs d'un arbre binaire */

#include "meo_ab_tp2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct noeud {
	int val; 
	struct noeud * pere; 
	struct noeud * gauche; 
	struct noeud * droit;
		} t_noeud;

t_noeud * racine;
t_noeud * nc;

void init_arbre(void){	
	racine=NULL;
	nc=NULL;
}

int arbre_vide(void){
	return (racine==NULL);
}

int hors_arbre(void){
	return (nc==NULL);
}

int filsg(void){
	if(!hors_arbre())	
		return(nc->gauche!=NULL);
	return 0;
}

int filsd(void){	
	if(!hors_arbre())	
		return(nc->droit!=NULL);
	return 0;
}

int feuille(void){
	if(!hors_arbre())	
		return(!filsd()&&!filsg());
	return 0;
}

void posit_rac(void){
	if(!arbre_vide()) 
		nc=racine;
}

void posit_pere(void){
	if(!hors_arbre()) 
		nc=nc->pere;
}

void posit_filsg(void){
	if(!hors_arbre()) 
		nc=nc->gauche;
}

void posit_filsd(void){
	if(!hors_arbre()) 
		nc=nc->droit;
}

void val_noeud(int * i){
	if(!hors_arbre()) 
		*i=nc->val;
}

void modif_noeud(int * i){
	if(!hors_arbre()) 
		nc->val=*i;
}

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
				nc=nc->pere;
				if(nc->gauche==ancien)
					nc->gauche=NULL;
				else
					nc->droit=NULL;
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





