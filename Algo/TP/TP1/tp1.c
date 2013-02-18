// HUBA THOMAS - Licence SPI - 2e année - Semestre 4 - TP1 Algo & Prog

/*
 * LIB
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * GLOBAL VALUE
 */

#define N 100

/*
 * TOOLS
 */

typedef enum {false,true} bool;

/*
 * EXERCICE 1
 */
// Calcule récursivement et affiche la factorielle d'un entier reçu en paramètre
int fact_recu(int n)
{
	int x; // Va prendre succéssivement les valeurs pendant la récursivité
	printf("Valeur : %i\n", n);
	// Si n = 1 alors on stop la récursivité
	if(n==1)
	{
		// Et on retourne n
		return n;
	}
	// Sinon
	else
	{
		// On donne a x la valeur de n * par la valeur de retour de
		// la fonction elle même avec comme paramètre n-1
		x=n*fact_recu(n-1);
		// Affichage de la valeur à chaque tour
		printf("fact : %i-\n",x);
		// On retourne la valeur de x
		return x;
	}
}

/*
 * EXERCICE 2
 */
// Affiche le nombre de chiffres d'un entier reçu en paramètre
int fibo_recu(int n)
{
	// Si n = 0 ou n = 1
	if(n==0 || n==1)
	{
		// On retourn 1
		return 1;
	}
	// Sinon 
	else
	{
		// On retourne la fonction avec n-1 + la fonction avec n - 2
		return fibo_recu(n-1)+fibo_recu(n-2);
	}
}

/*
 * EXERCICE 3
 */
// Version A
int fibo_recu_afficher_n(int n)
{
	// Si n = 0 ou n = 1
	if(n==0 || n==1)
	{
		// On retourn 1
		return 1;
	}
	// Sinon 
	else
	{
		// On retourne la fonction avec n-1 + la fonction avec n - 2
		return fibo_recu(n-1)+fibo_recu(n-2);
	}
}

// Version B (iter avec tableau)
int fibo_recu_tab(int n)
{
	int tab[N]; // Tableau de N case
	int i; // Itérateur de boucle
	// Dans les deux premières case du tableau, on place 1 pour respecter la suite de fibo
	tab[0]=1; 
	tab[1]=1;
	// Tant que l'on n'est pas à n
	for(i=2;i<=n;i++)
	{
		tab[i]=tab[i-1]+tab[i-2];
	}
	// On retourne la valeur de la case tab[n]
	return tab[n];
}

// Version C (tier sans tableau)

/*
 * EXERCICE 4
 */
// Test récursivement si la chaine de caractère reçu en paramètre est un palindrome
bool palindrome(char * ch, int deb, int fin)
{
	if(deb>=fin)
	{
		return true;
	}
	else if(ch[deb]==ch[fin])
	{
		return(palindrome(ch, deb+1, fin-1);
	}
	return false;
}

/*
 * PROGRAMME PRINCIPAL
 */
int main()
{
	int n; // Contient les valeurs demandées à l'utilisateur
	int choice; // Contient le choix de l'utilisateur

	// Affichage MENU
	printf("Bienvenue au TP1, entrez votre choix : \n");
	printf("1.Exercice 1 : Factorielle & Récursivité\n");
	printf("2.Exercice 2 : Fibonnaci & Récursivité\n");
	printf("3.Exercice 3a : Fibonnaci, Récursivité & affichage\n");
	printf("4.Exercice 3b : Fibonnaci & Itératife (Tableau)\n");
	printf("5.Exercice 3c : Fibonnaci & Itératife (Sans Tableau)\n");
	printf("6.Exercice 4 : Palindrome\n");
	printf("7.Exercice 5 :\n");
	printf("8.\n");
	// Attente du choix 
	printf("Votre choix : ");
	scanf("%i", &choice);
	
	// Traitement du choix 
	switch(choice)
	{
		case 1 : // Exercice 1
			printf("Entrer entier positif : ");
			scanf("%i",&n);
			while(n<0)
			{
				printf("Entrez entier positif : ");
				scanf("%i"&n);
			}
			n=fact_recu(n);
			printf("= %i\n", n);
			// END

		case 2 : // Exercice 2
			printf("Entrez entier positif : ");
			scanf("%i", &n);
			while(n<0)
			{
				printf("Entrez entier positif :  ");
				scanf("%i", &n);
			}
			n=fibo_recu(n);
			printf("%i\n", n);
			// END

		case 3 : // Exercice 3 récursive
			printf("TODO\n")
			// END

		case 4 : // Exercice 3 iter tableau
			printf("Entrez entier positif : ");
			scanf("%i", &n);
			while(n<0)
			{
				printf("Entrez entier positif : ");
				scanf("%i", &n);
			}
			n=fact_recu_tab(n);
			printf("%i\n", n);
			// END

		case 5 : // Exercice 3 iter sans tableau
			printf("TODO\n");
			//END

		case 6 : // Exercice 4
			int deb, fin; // Indice de début & fin de la chaine
			char tmp[100]; // Tampon de 100 case pour la chaine
			printf("Entrez votre chaine : ");
			scanf("%s",tmp);
			fin=strlen(tmp); // On récupère la taille de la chaine
			char * pal = tmp;
			bool word = palindrome(pal, deb, fin);
			// Affichage du résultat
			if(word)
			{
				printf("Il s'agit d'un palindrome.\n");
			}
			else
			{
				printf("Il ne s'agit pas d'un palindrome.\n");
			}
			// Free
			free(pal);
			// END

		case 7 : // Exercice 5
		case 8 : // Exercice Complémentaire : Tour de Hanoï
		default : break;
	}
	// END
	return 0
}


