#include "structure.h"
#include <stdio.h>
void ajouter_fin_chaine(liste_ordre *chaine,liste_ordre *a_ajouter){
  if (chaine != NULL) {
    /* code */
  }
  liste_ordre *ordre_courant = chaine;
  while (ordre_courant -> suivant != NULL) {
    ordre_courant = ordre_courant -> suivant;
  }
  ordre_courant -> suivant = a_ajouter;
  ordre_courant = NULL;
}
