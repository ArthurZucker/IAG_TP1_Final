#include "structure.h"
#include "dfss2.h"
#include <stdlib.h>
#include <stdio.h>
void dfs2(Graphe *graphe,int sommet_depart ,liste_ordre **ordre_par_sommet,liste_ordre **ordre_ancien_dfs){
	//La liste de sommet matquĂŠ est initialisĂŠe Ă  0 pour tous
  printf("___________________________________\nPartie 1: trouver l'ordre, le stocker et l'inverser\n" );
  int *ancien_dfs = (int *)malloc(sizeof(int));
  int *new_dfs = (int *)malloc(sizeof(int));
  liste_ordre *ordre_courant = ordre_ancien_dfs[0];
  int nb_composantes;
  for (size_t i = 0; i < graphe->nb_sommets -1; i++) {
    if (ordre_courant != NULL) {
      while (ordre_courant -> suivant != NULL) {
        ordre_courant = ordre_courant -> suivant;
      }
      ancien_dfs[nb_composantes] = ordre_courant -> nombre;
      nb_composantes ++;
    }
    ordre_courant = ordre_ancien_dfs[i+1];
  }
  for (size_t i = 0; i < nb_composantes; i++) {
    new_dfs[i] = ancien_dfs[nb_composantes-i-1];
    printf("%d\n",new_dfs[i] );
  }
  printf("___________________________________\nPartie 2: appliquer le dfs avec cet ordre\n" );
  int taille = graphe -> nb_sommets;
  //free(ancien_dfs);
	int *sommet_marque = (int *)calloc((taille+1),sizeof(int)); // sommet_marque[sommet] = 1 pour marquer un sommets
	for (int i = 1; i < nb_composantes+1 ; ++i)
	{
		liste_ordre *ordre = (liste_ordre *)malloc(sizeof(liste_ordre));
		if (sommet_marque[new_dfs[i-1]]!=1) {
			sommet_marque[new_dfs[i-1]] = 1;
			ordre -> nombre = new_dfs[i];
			ordre -> suivant = NULL;
			dfss2(graphe,new_dfs[i-1],sommet_marque,ordre);
			ordre_par_sommet[i-1] = ordre;
		}
		else{
			ordre -> suivant = NULL;
			ordre_par_sommet[i-1] = NULL;
			afficher_liste_ordre(NULL);
		}
	}
  //free(new_dfs);
}
