#include "structure.h"
#include "dfss.h"
#include "create_sommet.h"
#include <stdlib.h>
#include <stdio.h>
#include "ajouter_fin_chaine.h"
void dfss(Graphe *graphe,Graphe *graphe2,int sommet, int *sommet_marque, liste_ordre *ordre){
  sommet_marque[sommet] = 1; //On marque que le sommet est visitĂŠ
  /*int i = 0;
  while ((graphe->liste_successeurs)[sommet-1][i] != 0 && i < graphe->nb_sommets) {
    if ((sommet_marque[(graphe->liste_successeurs)[sommet-1][i]]!=1)) {
      create_sommet(graphe2,sommet,(graphe->liste_successeurs)[sommet-1][i]);
      liste_ordre *ordre_ajouter = (liste_ordre *)malloc(sizeof(liste_ordre));
      ordre_ajouter -> pre_ordre= (graphe->liste_successeurs)[sommet-1][i];
      ordre_ajouter -> suivant = NULL;
      ajouter_fin_chaine(ordre,ordre_ajouter);
      dfss(graphe,graphe2,(graphe->liste_successeurs)[sommet-1][i],sommet_marque,ordre);
    }
    i++;
  }*/
  int i = (graphe->pi[sommet- 1]) ;
  while (i < (graphe->pi[sommet])) {
    if ((sommet_marque[(graphe->alpha)[i]] != 1 ) && (graphe->alpha)[i] != -1 ){
      create_sommet(graphe2,sommet,(graphe->alpha)[i]);
      liste_ordre *ordre_ajouter = (liste_ordre *)malloc(sizeof(liste_ordre));
      ordre_ajouter -> pre_ordre= (graphe->alpha)[i];
      ordre_ajouter -> suivant = NULL;
      ajouter_fin_chaine(ordre,ordre_ajouter);
      dfss(graphe,graphe2,(graphe->alpha)[i],sommet_marque,ordre);
    }
    i++;
  }
}
