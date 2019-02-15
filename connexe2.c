#include "structure.h"
#include <stdio.h>
int connexe2(Graphe *graphe,liste_ordre **ordre_dfs){
  // On va parcourir les dfs de chaque sommets, et vĂŠrifier
  // Que tous les sommets apparaissent dedans
  liste_ordre *ordre_courant = ordre_dfs[1];
  int taille = graphe->nb_sommets;
  for (int i = 1; i < taille+1; i++) {
    if (ordre_courant != NULL) {
      return 0;
    }
    ordre_courant =  ordre_dfs[i];
  }
  return 1;
}
