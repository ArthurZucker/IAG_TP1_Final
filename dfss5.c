#include "structure.h"
#include <stdlib.h>
#include <stdio.h>
#include "ajouter_fin_chaine.h"
void dfss5(Graphe *graphe,int sommet, int *sommet_marque, liste_ordre *ordre){
  sommet_marque[sommet] = 1; //On marque que le sommet est visité
  /*int i = 0;
  while ((graphe->liste_successeurs)[sommet-1][i] != 0 && i < graphe->nb_sommets) {
    if ((sommet_marque[(graphe->liste_successeurs)[sommet-1][i]]!=1)) {
      liste_ordre *ordre_ajouter = (liste_ordre *)malloc(sizeof(liste_ordre));
      ordre_ajouter -> pre_ordre = (graphe->liste_successeurs)[sommet-1][i];
      ordre_ajouter -> suivant = NULL;
      liste_ordre *ordre_ajouter2 = (liste_ordre *)malloc(sizeof(liste_ordre));
      ordre_ajouter2 -> pre_ordre = sommet;
      ordre_ajouter2 -> suivant = NULL;
      ajouter_fin_chaine(ordre,ordre_ajouter);
      dfss5(graphe,(graphe->liste_successeurs)[sommet-1][i],sommet_marque,ordre);
      printf("Le dernier ajout bug\n" );
      afficher_liste_ordre(ordre);
      if (ordre_ajouter -> suivant   == NULL) {
        ajouter_fin_chaine(ordre,ordre_ajouter2); //la remontée
      }

    }
    i++;
  }*/
  int i = (graphe->pi[sommet- 1]) ;
  while (i < (graphe->pi[sommet])) {
    if ((sommet_marque[(graphe->alpha)[i]] == 0 ) && (graphe->alpha)[i] != -1 ){
      liste_ordre *ordre_ajouter = (liste_ordre *)malloc(sizeof(liste_ordre));
      ordre_ajouter -> pre_ordre= (graphe->alpha)[i];
      ordre_ajouter -> suivant = NULL;
      ordre_ajouter -> post_ordre = sommet;
      printf("BUGG\n");
      //ajouter_fin_chaine(ordre,ordre_ajouter2); //la remontée
      ajouter_fin_chaine(ordre,ordre_ajouter);
      dfss5(graphe,(graphe->alpha)[i],sommet_marque,ordre);
      //afficher_liste_ordre(ordre);
    }
    i++;
  }
}
