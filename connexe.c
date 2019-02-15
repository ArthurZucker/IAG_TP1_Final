#include "structure.h"
#include <stdio.h>
int connexe(int **sommet_marque_dugraphe, int taille){
  // On va parcourir les dfs de chaque sommets, et vĂŠrifier
  // Que tous les sommets apparaissent dedans
  for (int i = 1; i < taille; i++) {
    for (int ii = 1; ii < taille  ; ii++) {
      if (sommet_marque_dugraphe[i][ii] ==0 ) {
        return 0;
      }
    }
  }
  return 1;
}
