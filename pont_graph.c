#include "structure.h"
#include <stdio.h>
#include "connexe2.h"
#include "initialize_all.h"
int pont_graph(Graphe *graphique){
  int taille = graphique -> nb_sommets;
  for (int i = 0; i < taille; i++) {
    for (int j= 0; j < taille; j++) {
      if ((graphique->liste_adjacence)[i+1][j+1] == 1) {
        (graphique->liste_adjacence)[i+1][j+1] = 0;
        if ( !connexe2(graphique) ) {
          printf("Lisaison supprimée entre %d et %d\n",i+1,j+1 );
          (graphique->liste_adjacence)[i+1][j+1] =1;
          return 1;
        }
        else{
        (graphique->liste_adjacence)[i+1][j+1] = 1;
        }
      }
    }
  }
  return 0;
}
