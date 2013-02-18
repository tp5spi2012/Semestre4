
#ifndef __MEO_AB_H__
#define __MEO_AB_H__

/* Mise en oeuvre par pointeurs d'un arbre binaire */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void init_arbre(void);
int arbre_vide(void);
int hors_arbre(void);
int filsg(void);
int filsd(void);
int feuille(void);
void posit_rac(void);
void posit_pere(void);
void posit_filsg(void);
void posit_filsd(void);
void val_noeud(char* mot);
int get_id();
void modif_noeud(char* mot);
void oter_feuille(void);
void ajout_filsg(int id, char* mot);
void ajout_filsd(int id, char* mot);
void affiche();
void affiche_rec(int, char*);
#endif 

