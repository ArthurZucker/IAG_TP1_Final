#include "structure.h"
#include <stdio.h>
void free_graphique(Graphe *graphique){
  int taille =graphique->nb_sommets;
  for (size_t i = 0; i < taille; i++) {
    free( (graphique->liste_successeurs)[i] );
  }
  for (int i = 0; i < taille+1; i++) {
    free((graphique->liste_adjacence)[i]);
  }
  free(graphique->liste_adjacence);
  free(graphique -> pi);
  free(graphique-> alpha);
  free(graphique);
}
