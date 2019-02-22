#include "structure.h"
void initialize_all(Graphe *graph){
  int taille =(graph->nb_sommets);
  graph -> liste_successeurs = (int **)malloc(((graph -> nb_sommets))*sizeof(int *));
  for (int i = 0; i < ((graph -> nb_sommets )); ++i)
  {
    (graph -> liste_successeurs)[i] = (int *)calloc(((graph -> nb_sommets)),sizeof(int ));
  }
  (graph -> alpha) = (int *)malloc(sizeof(int ));
  (graph -> pi) = (int *)calloc(((graph -> nb_sommets)),sizeof(int )); //Askip non free
  int cpt = 0;
  int cpt1 = 0;
  int cpt2 = 1;
  for (int i = 1; i < taille+1; i++) {
    if (cpt2 == 1) {
      (graph->pi)[i-1] = cpt;
    }
    else{
      (graph->pi)[i-1] = -1;
    }
    for (int ii = 1; ii < taille+1; ii++) {
      if ((graph->liste_adjacence)[i][ii]==1) {
        (graph->liste_successeurs)[i-1][cpt1]=ii;
        (graph->alpha) = (int *)realloc((graph->alpha),(cpt+cpt1+1)*sizeof(int ));
        (graph->alpha)[cpt] = ii;
        cpt++;
        cpt1++;
        cpt2=1;
      }
    }
    if (cpt1==0) {
      cpt2=0;
      //(graph->alpha)[cpt-1] = -1;
    }
    cpt1 = 0;
  }
  for (int i = 0; i < taille; i++) {
    if (graph->liste_successeurs[i][0] == 0) {
      (graph->alpha)[(graph->pi)[i]-1] = -1;
    }
  }
}

void initialize_all2(Graphe *graph){
  int taille =(graph->nb_sommets);
  int cpt = 0;
  int cpt1 = 0;
  int cpt2 = 1;
  for (int i = 1; i < taille+1; i++) {
    if (cpt2 == 1) {
      (graph->pi)[i-1] = cpt;
    }
    else{
      (graph->pi)[i-1] = -1;
    }
    for (int ii = 1; ii < taille+1; ii++) {
      if ((graph->liste_adjacence)[i][ii]==1) {
        (graph->liste_successeurs)[i-1][cpt1]=ii;
        (graph->alpha) = (int *)realloc((graph->alpha),(cpt+cpt1+1)*sizeof(int ));
        (graph->alpha)[cpt] = ii;
        cpt++;
        cpt1++;
        cpt2=1;
      }
    }
    if (cpt1==0) {
      cpt2=0;
      //(graph->alpha)[cpt-1] = -1;
    }
    cpt1 = 0;
  }
  for (int i = 0; i < taille; i++) {
    if (graph->liste_successeurs[i][0] == 0) {
      (graph->alpha)[(graph->pi)[i]-1] = -1;
    }
  }
}
