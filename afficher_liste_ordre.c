#include <stdio.h>
#include "structure.h"
void afficher_liste_ordre(liste_ordre *ordre){
  liste_ordre *ordre_courant = ordre;
  printf("[");
  while (ordre_courant != NULL) {
    printf("(%3d,%3d)->",ordre_courant -> post_ordre, ordre_courant -> pre_ordre);

    ordre_courant = ordre_courant -> suivant;
  }
  printf("]\n");
}
