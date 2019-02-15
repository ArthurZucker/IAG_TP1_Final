#include <stdio.h>
void afficher_mat(int **matrice,int taille){
	if (taille == 0) {
		printf("|" );
		int i = 0;
		while (matrice[i] != NULL) {
			printf("%2d", matrice[i]);
			i++;
		}
		printf("|\n");
	}
	for (int i = 0; i < taille; ++i)
	{
		printf("|" );
		for (int ii = 0; ii < taille; ++ii)
		{
			if (matrice[i][ii] == 1)
			{
				printf("\033[0;31m");
			}
			printf("%2d", matrice[i][ii]);
			printf("\033[0m");
		}
		printf("|\n");
	}
}
