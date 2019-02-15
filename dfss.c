#include "structure.h"
#include <stdlib.h>
#include <stdio.h>
#include "ajouter_fin_chaine.h"
void dfss(Graphe *graphe,Graphe *graphe2,int sommet, int *sommet_marque, liste_ordre *ordre){
  sommet_marque[sommet] = 1; //On marque que le sommet est visité
  int i = 0;
  while ((graphe->liste_successeurs)[sommet-1][i] != 0 && i < graphe->nb_sommets) {
    //printf("Nous sommes dans DFSS, à ce momenet en entrée ordre vaut\n" );
    //afficher_liste_ordre(ordre);
    if ((sommet_marque[(graphe->liste_successeurs)[sommet-1][i]]!=1)) {
      // Le sommet à un voisin, i
      // On va donc passer par i : ajouter en fin de chaine i
      create_sommet(graphe2,sommet,(graphe->liste_successeurs)[sommet-1][i]);
      liste_ordre *ordre_ajouter = (liste_ordre *)malloc(sizeof(liste_ordre));
      ordre_ajouter -> nombre= (graphe->liste_successeurs)[sommet-1][i];
      ordre_ajouter -> suivant = NULL;
      ajouter_fin_chaine(ordre,ordre_ajouter);
      dfss(graphe,graphe2,(graphe->liste_successeurs)[sommet-1][i],sommet_marque,ordre);
      //Ici on reviens au sommet i, remettre le numéro du sommet pour les cfc ??
      // dfss2 pour gérer les ordres??
    }
    i++;
  }
}
