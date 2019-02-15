#include "structure.h"
#include "dfs2.h"
#include "inverser.h"
#include <stdio.h>
void composantes_fortement_connexes(Graphe *graph, liste_ordre **composantes){
  size_t taille =(graph->nb_sommets);
  int *sommet_marque1 = (int *)calloc(taille,sizeof(int)); // sommet_marque[sommet] = 1 pour marquer un sommet
  liste_ordre **ordre = (liste_ordre **)malloc(sizeof(liste_ordre *));
  liste_ordre **ordre2 = (liste_ordre **)malloc(sizeof(liste_ordre *));
  int liste_ancien = (int *)calloc(taille,sizeof(int));
	printf("Premier DFS\n" );
  int **sommet_marque_dugraphe = (int **)calloc((taille+1),sizeof(int *));
	for (int i = 0; i < taille+1; i++) {
		sommet_marque_dugraphe[i] = (int *)calloc((taille+1),sizeof(int));
	}
  printf("OK\n" );
	dfs3(graph,(graph->liste_adjacence)[0][1],ordre,sommet_marque_dugraphe);
  printf("Inverse du graphe\n");
  inverser(graph);
  dfs2(graph,(graph->liste_adjacence)[0][1],composantes,ordre);
  printf("CO fini\n" );
}
