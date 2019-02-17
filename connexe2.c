#include "structure.h"
#include "dfs4.h"
#include "initialize_all.h"
#include "free_graphique.h"
#include "afficher_liste_ordre.h"
#include <stdio.h>
int connexe2(Graphe *graphe){
  // On va parcourir les dfs de chaque sommets, et vĂŠrifier
  // Que tous les sommets apparaissent dedans
  int taille = graphe->nb_sommets;
  liste_ordre **tableau = (liste_ordre **)malloc((taille+1)*sizeof(liste_ordre *));
  int **sommet_marque_dugraphe = (int **)calloc((taille+1),sizeof(int *));
  for (int i = 0; i < taille; i++) {
    sommet_marque_dugraphe[i] = (int *)calloc((taille+1),sizeof(int));
  }
  Graphe *graphique2 = (Graphe *)malloc(sizeof(Graphe ));
  graphique2 -> nb_sommets = taille;
  graphique2 -> nb_aretes  =(graphe-> nb_aretes);
  graphique2 -> oriente = graphe -> oriente;
  graphique2 -> liste_adjacence = (int **)calloc(taille+1,(sizeof(int *)));
  for (size_t i = 0; i < taille+1; i++) {
      graphique2->liste_adjacence[i] = (int *)calloc(taille+1,(sizeof(int )));
  }
  for (int i = 0; i < taille +1; ++i)
  {
     (graphique2->liste_adjacence)[0][i] = i;
     (graphique2->liste_adjacence)[i][0] = i;
  }
  for (size_t i = 1; i < taille+1; i++) {
    for (size_t ii = 1; ii < taille+1; ii++) {
      (graphique2->liste_adjacence)[i][ii] = (graphe->liste_adjacence)[i][ii];
      (graphique2->liste_adjacence)[ii][i] = (graphe->liste_adjacence)[ii][i];
    }
  }
  initialize_all(graphique2);
  dfs4(graphique2,1,tableau,sommet_marque_dugraphe);
  liste_ordre *ordre_courant = tableau[1];
  for (int i = 1; i < taille+1; i++) {
    if (ordre_courant != NULL) {
      for (size_t i = 0; i < taille; i++) {
        afficher_liste_ordre(tableau[i]);
      }

      return 0;
    }
    ordre_courant =  tableau[i];
  }
  for (size_t i = 0; i < taille; i++) {
    free(tableau[i]);
    free(sommet_marque_dugraphe[i]);
  }
  free(sommet_marque_dugraphe);
  free(tableau);
  free_graphique(graphique2);
  return 1;

}
