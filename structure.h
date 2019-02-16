#ifndef structure__h
#define structure__h structure__h
#include <stdlib.h>
#include <stdio.h>
typedef struct Graphe{
	int nb_aretes;
	int nb_sommets;
	int oriente;
	int **liste_incidence;
	int *alpha;
	int *pi;
	int **liste_adjacence;
	int **liste_successeurs;
}Graphe;
typedef struct liste_ordre{
	int pre_ordre;
	int post_ordre;
	struct liste_ordre *suivant;
}liste_ordre;
#endif
