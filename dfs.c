#include "structure.h"
#include "dfss.h"
#include <stdlib.h>
#include <stdio.h>
void dfs(Graphe *graphe,Graphe *graph2,int sommet_depart ,liste_ordre **ordre_par_sommet, int **sommet_marque_dugraphe){
	//La liste de sommet matquĂŠ est initialisĂŠe Ă  0 pour tous
	//La liste de sommet matquĂŠ est initialisĂŠe Ă  0 pour tous
	size_t taille = graphe->nb_sommets;
	int *sommet_marque = (int *)calloc((taille+1),sizeof(int)); // sommet_marque[sommet] = 1 pour marquer un sommets
	for (int i = 1; i < sommet_depart  ; ++i)
	{
		liste_ordre *ordre = (liste_ordre *)malloc(sizeof(liste_ordre));
		if (sommet_marque[i]!=1) {
			sommet_marque[i] = 1;
			ordre -> pre_ordre = i;
			ordre -> suivant = NULL;
			dfss(graphe,graph2,i,sommet_marque,ordre);
			ordre_par_sommet[i-1] = ordre;
		}
		else{
			ordre -> suivant = NULL;
			ordre_par_sommet[i-1] = NULL;
		}

		for (int ii = 0; ii < taille+1; ii++) {
			sommet_marque_dugraphe[i-1][ii] = sommet_marque[ii];
		}
	}
	for (int i = sommet_depart; i < taille+1 ; ++i)
	{
		liste_ordre *ordre = (liste_ordre *)malloc(sizeof(liste_ordre));
		if (sommet_marque[i]!=1) {
			sommet_marque[i] = 1;
			ordre -> pre_ordre = i;
			ordre -> suivant = NULL;
			dfss(graphe,graph2,i,sommet_marque,ordre);
			ordre_par_sommet[i-1] = ordre;
		}
		else{
			ordre -> suivant = NULL;
			ordre_par_sommet[i-1] = NULL;
		}
		for (int ii = 0; ii < taille+1; ii++) {
			sommet_marque_dugraphe[i-1][ii] = sommet_marque[ii];
		}
	}
	free(sommet_marque);
}
