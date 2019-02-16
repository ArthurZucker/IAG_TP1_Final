#include "structure.h"
#include "dfs2.h"
#include "inverser.h"
#include "dfs3.h"
#include "create_dot.h"
#include "free_ordre.h"
#include "afficher_liste_ordre.h"
#include <stdio.h>
void composantes_fortement_connexes(Graphe *graph, liste_ordre **composantes){
  size_t taille =(graph->nb_sommets);
  liste_ordre **ordre_ancien_dfs = (liste_ordre **)malloc((taille)*sizeof(liste_ordre *));
  int **sommet_marque_dugraphe = (int **)calloc((taille+1),sizeof(int *));
	for (int i = 0; i < taille+1; i++) {
		sommet_marque_dugraphe[i] = (int *)calloc((taille+1),sizeof(int));
	}
	dfs3(graph,(graph->liste_adjacence)[0][1],ordre_ancien_dfs,sommet_marque_dugraphe);
  inverser(graph);
  char *nom_fichier3;
	nom_fichier3 = "digraph-1-predfs_inverse.dot";;
	create_dot(graph,nom_fichier3);
  dfs2(graph,(graph->liste_adjacence)[0][1],composantes,ordre_ancien_dfs);
  for (size_t i = 0; i < taille; i++) {
    if (ordre_ancien_dfs[i] != NULL) {
      afficher_liste_ordre(ordre_ancien_dfs[i]);
      free_ordre(ordre_ancien_dfs[i]);
    }
    if (sommet_marque_dugraphe[i] != NULL) {
      free(sommet_marque_dugraphe[i]);
    }

  }
  if (ordre_ancien_dfs != NULL) {
    free(ordre_ancien_dfs);
  }
  free(sommet_marque_dugraphe);
}
