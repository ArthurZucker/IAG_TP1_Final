#include "structure.h"
#include "initialize_all.h"
#include <stdio.h>
void inverser(Graphe *graphique){
  if (graphique -> oriente != 1) {
    printf("Le graphique n'est pas orienté, sont inverse est lui même\n" );
  }
  else{
    int **inverse = (int **)calloc(((graphique -> nb_sommets)+1),sizeof(int *));
    for (int i = 0; i < ((graphique -> nb_sommets )+1); ++i)
    {
    	inverse[i] = (int *)calloc(((graphique -> nb_sommets)+1),sizeof(int ));
    }
    for (int i = 0; i < (graphique -> nb_sommets ) +1; ++i)
    {
    	inverse[0][i] = i;
			inverse[i][0] = i;
      for (size_t ii = 1; ii < (graphique -> nb_sommets ) +1; ii++) {
        inverse[ii][i] = (graphique ->liste_adjacence)[i][ii];
      }
    }
    graphique -> liste_adjacence = inverse;
  }
  initialize_all(graphique);
}
