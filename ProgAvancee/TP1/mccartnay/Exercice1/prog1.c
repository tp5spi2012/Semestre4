/* mccartnay */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 10000
#define TAILLE 500

typedef struct S_s {
	int * tab_int[TAILLE];
	char tab_char[TAILLE];
} S_t;

S_t tab[N];

char f3 () {
	char c = 'a' + (rand() % ('z'+1));
	return c;
}


int * f2 () {
	int * i = malloc(sizeof(int));
	*i = rand();
	return i;
}


void f1 (S_t * p1) {
	printf("Entrée dans f1\n");
	int i, j;
	for (i = 0; i< N; i++) {
		for (j = 0; j < TAILLE; j++) {
			tab[i].tab_int[j] = f2();
			tab[i].tab_char[j] = f3();
		}
		free(tab[i].tab_int[j]);
	}
}



int main() {
	S_t * tabi = malloc(sizeof(S_t)*N);
	printf("Debut du programme\n");
	srand(getpid());
	printf("Appel de f1\n");
	f1(tabi);
	printf( "Retour de f1\n");
	printf("Fin normale du programme\n");
	free(tabi);
	return 0;
}
