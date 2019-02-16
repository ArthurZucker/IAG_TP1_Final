#include "structure.h"
#include "dfs2.h"
#include "inverser.h"
#include "dfs3.h"
#include "create_dot.h"
#include <stdio.h>
void composantes_fortement_connexes(Graphe *graph, liste_ordre **composantes){
  size_t taille =(graph->nb_sommets);
  //int *sommet_marque1 = (int *)calloc(taille,sizeof(int)); // sommet_marque[sommet] = 1 pour marquer un sommet
  liste_ordre **ordre_ancien_dfs = (liste_ordre **)malloc(sizeof(liste_ordre *));
  int **sommet_marque_dugraphe = (int **)calloc((taille+1),sizeof(int *));
	for (int i = 0; i < taille+1; i++) {
		sommet_marque_dugraphe[i] = (int *)calloc((taille+1),sizeof(int));
	}
  printf("Premier DFS\n" );
  printf("OK\n" );
	dfs3(graph,(graph->liste_adjacence)[0][1],ordre_ancien_dfs,sommet_marque_dugraphe);
  printf("Le dfs dans connexe à donné\n");
  for (size_t i = 0; i < taille; i++) {
    afficher_liste_ordre(ordre_ancien_dfs[i]);
  }
  inverser(graph);
  char *nom_fichier3;
	nom_fichier3 = "digraph-1-predfs_inverse.dot";;
	create_dot(graph,nom_fichier3);
  printf("DFS 2 avec nouvel ordre\n" );
  dfs2(graph,(graph->liste_adjacence)[0][1],composantes,ordre_ancien_dfs);
  //free(sommet_marque1);
  printf("CO fini\n" );
}
