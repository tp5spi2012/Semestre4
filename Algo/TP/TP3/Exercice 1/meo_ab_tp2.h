
#ifndef __MEO_AB_H__
#define __MEO_AB_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Mise en oeuvre par pointeurs d'un arbre binaire */

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
void val_noeud(int * mot);
void modif_noeud(int * i);
void oter_feuille(void);
void ajout_filsg(int i);
void ajout_filsd(int i);
#endif 

